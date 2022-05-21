#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000

bitset<MAX_N> prime;

void sieve(int n = MAX_N) {
    prime.flip();
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (!prime[p]) {
            continue;
        }

        for (int i = p * p; i <= n; i += p) {
            prime[i] = false;
        }
    }
}

vector<int> get_primes() {
    sieve();

    vector<int> primes;
    for (int p = 2; p <= MAX_N; ++p) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}
