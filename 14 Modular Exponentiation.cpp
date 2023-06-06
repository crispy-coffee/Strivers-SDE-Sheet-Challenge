#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
    if (m == 1) {
        return 0; // Modulo 1 is always 0
    }

    long long result = 1;
    long long base = x % m;

    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        n /= 2;
    }

    return (int)result;
}
