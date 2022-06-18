#include <bits/stdc++.h>
using namespace std;

const int MAX_K = 1e6;

bitset<MAX_K + 1> prime;

void sieve() {
    prime.flip();
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= MAX_K; ++p) {
        if (!prime[p]) {
            continue;
        }

        for (int i = p * p; i <= MAX_K; i += p) {
            prime[i] = false;
        }
    }
}

bool divide(string dividend, int divisor) {
    int remainder = 0;
    for (int i = 0; i < (int) dividend.size(); ++i) {
        remainder = (10 * remainder + (dividend[i] - '0')) % divisor;
    }
    return remainder == 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sieve();

    string password;
    int k;
    cin >> password >> k;

    for (int i = 2; i < k; ++i) {
        if (!prime[i]) {
            continue;
        }

        if (divide(password, i)) {
            cout << "BAD" << ' ' << i;
            return 0;
        }
    }

    cout << "GOOD";
    return 0;
}
