#include <bits/stdc++.h>

using namespace std;

// Modular exponentiation
int mod_exp(int base, int exp, int mod)
{
    int res = 1;
    base %= mod;
    while (exp)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// GCD
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

// Modular inverse (brute force)
int mod_inv(int e, int phi)
{
    for (int d = 1; d < phi; d++)
        if ((e * d) % phi == 1)
            return d;
    return -1;
}

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

    int e = 3;
    while (gcd(e, phi) != 1)
        e++;

    int d = mod_inv(e, phi);

    cout << "Public Key: (" << e << ", " << n << ")\n";
    cout << "Private Key: (" << d << ", " << n << ")\n";

    string msg;
    cout << "Enter message: ";
    getline(cin, msg);

    vector<int> enc(msg.length());

    cout << "Encrypted: ";
    for (size_t i = 0; i < msg.length(); i++)
    {
        enc[i] = mod_exp((int)msg[i], e, n);
        cout << enc[i] << " ";
    }

    cout << "\nDecrypted: ";
    for (size_t i = 0; i < msg.length(); i++)
    {
        cout << (char)mod_exp(enc[i], d, n);
    }
    cout << endl;

    return 0;
}