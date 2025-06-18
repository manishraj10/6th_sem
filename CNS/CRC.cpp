#include <iostream>
using namespace std;

// Perform bitwise XOR between encoded message and generator
string xorDivision(string encoded, const string &generator)
{
    int genLen = generator.length();

    for (int i = 0; i <= encoded.length() - genLen;)
    {
        // Perform XOR only if current bit is 1
        if (encoded[i] == '1')
        {
            for (int j = 0; j < genLen; ++j)
            {
                encoded[i + j] = (encoded[i + j] == generator[j]) ? '0' : '1';
            }
        }
        // Move to the next '1' in the message
        while (i < encoded.length() && encoded[i] != '1')
            ++i;
    }

    return encoded;
}

int main()
{
    string data, generator;

    cout << "\n----------- Sender Side -----------\n";
    cout << "Enter Data bits: ";
    cin >> data;

    cout << "Enter Generator polynomial (in binary): ";
    cin >> generator;

    int genLen = generator.length();
    string encoded = data + string(genLen - 1, '0'); // Append (genLen - 1) zeros

    string remainder = xorDivision(encoded, generator);
    string checksum = remainder.substr(remainder.length() - genLen + 1);

    string transmitted = data + checksum;

    cout << "Checksum generated: " << checksum << endl;
    cout << "Transmitted message: " << transmitted << endl;

    cout << "\n----------- Receiver Side -----------\n";
    cout << "Enter received message: ";
    string received;
    cin >> received;

    string receivedRemainder = xorDivision(received, generator);
    string checkPart = receivedRemainder.substr(receivedRemainder.length() - genLen + 1);

    if (checkPart.find('1') != string::npos)
        cout << "Error detected in transmission.\n";
    else
        cout << "No Error. Transmission successful!\n";

    return 0;
}