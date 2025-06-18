#include <iostream>
#include <queue>

using namespace std;

// Function to simulate the leaky bucket algorithm
void leakyBucket(int outputRate, int bucketSize)
{
    queue<int> bucket; // To hold the packets
    int currentTime = 0;

    // Simulating incoming packets
    while (true)
    {
        int incomingPacket;
        cout << "Enter incoming packet size (enter 0 to stop): ";
        cin >> incomingPacket;

        if (incomingPacket == 0)
        {
            break; // Exit when the user enters 0
        }

        // Add packets to the bucket (if it doesn't overflow)
        if (bucket.size() + incomingPacket <= bucketSize)
        {
            for (int i = 0; i < incomingPacket; i++)
            {
                bucket.push(1); // Representing a packet
            }
        }
        else
        {
            cout << "Overflow! Dropping packets." << endl;
            while (!bucket.empty())
                bucket.pop(); // Empty the bucket to simulate dropping
        }

        // Print information before starting the transmission
        cout << "--------------------------------------------------\n";
        cout << "Incoming packet: " << incomingPacket << endl;
        cout << "Transmission left: " << bucket.size() << endl;

        // Transmit packets at the defined output rate
        while (!bucket.empty())
        {
            // Transmit up to `outputRate` packets per second
            for (int i = 0; i < outputRate && !bucket.empty(); i++)
            {
                bucket.pop(); // Transmit a packet (remove it from the bucket)
            }

            // Display time and remaining bytes after transmission
            cout << "Time: " << currentTime << " seconds - Transmitted " << outputRate << " packets" << endl;
            cout << "Bytes remaining: " << bucket.size() << endl;

            // Increment current time (simulate time passing)
            currentTime++;
        }
    }
}

int main()
{
    int outputRate, bucketSize;

    // Read output rate and bucket size from user
    cout << "Enter output rate (packets per second): ";
    cin >> outputRate;
    cout << "Enter bucket size (maximum packets): ";
    cin >> bucketSize;

    // Call the leaky bucket simulation function
    leakyBucket(outputRate, bucketSize);

    return 0;
}