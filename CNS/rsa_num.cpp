#include <bits/stdc++.h>

using namespace std;

// Function to compute GCD
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute (base^exp) % mod using modular exponentiation
int mod_pow(int base, int exp, int mod)
{
    int result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}

// Function to find modular inverse of e under mod phi using Extended Euclidean Algorithm
int mod_inverse(int e, int phi)
{
    int t = 0, t1 = 1;
    int r = phi, r1 = e;

    while (r1 != 0)
    {
        int q = r / r1;

        int temp = t;
        t = t1;
        t1 = temp - q * t1;

        temp = r;
        r = r1;
        r1 = temp - q * r1;
    }

    if (r > 1)
        return -1; // Inverse doesn't exist
    if (t < 0)
        t += phi;

    return t;
}

// Function to check if a number is prime (naive check)
bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    srand(time(0));

    // Choose two small primes
    int p = 0, q = 0;
    while (!is_prime(p))
        p = rand() % 100 + 50;
    while (!is_prime(q) || q == p)
        q = rand() % 100 + 50;

    cout << "Chosen primes:\n  p = " << p << "\n  q = " << q << endl;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    int e = 3;
    while (gcd(e, phi) != 1)
        e += 2;

    // Compute d
    int d = mod_inverse(e, phi);
    if (d == -1)
    {
        cout << "Modular inverse of e doesn't exist. Exiting...\n";
        return 1;
    }

    cout << "Public key (e, n): (" << e << ", " << n << ")\n";
    cout << "Private key (d, n): (" << d << ", " << n << ")\n";

    // Message to encrypt
    int message;
    cout << "\nEnter a number to encrypt (as message): ";
    cin >> message;

    // Encrypt
    int encrypted = mod_pow(message, e, n);
    cout << "Encrypted message: " << encrypted << endl;

    // Decrypt
    int decrypted = mod_pow(encrypted, d, n);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}