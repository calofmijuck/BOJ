#include <bits/stdc++.h>
using namespace std;
#define N 1010101
typedef long long ll;

bitset<N> prime;

int main() {
    ll m, n;
    prime.set();
    prime[1] = 0;
    scanf("%lld %lld", &m, &n);
    for(ll p = 2; p <= n; ++p) {
        if(prime[p]) {
            if(m <= p && p <= n) printf("%d\n", p);
            for(ll k = p * p; k <= n; k += p)
                prime[k] = 0;
        }
    }
    return 0;
}
