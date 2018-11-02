#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_RES = 25505460948L;

ll mySqrt(ll n) {
    ll r = (ll)sqrt(n) + 10;
    while (r * r > n) r--;
    return r;
}

ll count(ll n) {
    ll m = mySqrt(n);
    vector<ll> prime;
    vector<short> mu(m + 1, -2);
    ll result = 0;
    for(ll p = 2; p <= m; p++) {
        if(mu[p] == -2) {
            mu[p] = -1;
            prime.push_back(p);
        }
        result -= mu[p] * n / (p * p);
        for(int i = 0; i < (int)prime.size() && p * prime[i] <= m; i++) {
            mu[p * prime[i]] = -mu[p];
            if(p % prime[i] == 0) {
                mu[p * prime[i]] = 0;
                break;
            }
        }
    }
    return result;
}

ll squareFree(ll n) {
    ll low = 1, high = MAX_RES, c;
    while(low < high) {
        ll mid = (low + high) >> 1;
        c = count(mid);
        if(c < n) low = mid + 1;
        else high = mid;
    }
    return high;
}

int main() {
    ll n; scanf("%lld", &n);
    printf("%lld\n", squareFree(n));
    return 0;
}
