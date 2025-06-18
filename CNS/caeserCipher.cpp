#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string caesarCipher(string text, int shift)
{
    string result = "";
    shift = shift % 26;
    for (char &ch : text)
    {
        if (isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + shift) % 26 + base;
        }
        result += ch;
    }
    return result;
}

string caesarDecipher(string text, int shift)
{
    string result = "";
    shift = shift % 26;
    for (char &ch : text)
    {
        if (isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base - shift + 26) % 26 + base;
        }
        result += ch;
    }
    return result;
}

int main()
{
    string text;
    int shift;

    cout << "Enter the plain text: ";
    cin >> text;

    cout << "Enter shift value: ";
    cin >> shift;

    string encrypted = caesarCipher(text, shift);
    cout << "Cipher text: " << encrypted << endl;

    string decrypted = caesarDecipher(encrypted, shift);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}