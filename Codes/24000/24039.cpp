#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20000

bool prime[MAX_N];

vector<int> get_primes() {
    memset(prime, true, sizeof(prime));

    prime[0] = prime[1] = false;
    for (int p = 2; p * p < MAX_N; ++p) {
        if (!prime[p]) {
            continue;
        }

        for (int i = p * p; i < MAX_N; i += p) {
            prime[i] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i < MAX_N; ++i) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    vector<int> primes = get_primes();
    
    for (int i = 0; i < (int) primes.size(); ++i) {
        int product = primes[i] * primes[i + 1];
        if (product > n) {
            cout << product;
            return 0;
        }
    }
    return 0;
}
