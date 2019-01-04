#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fac[1001], cnt;

void factors(ll n) {
    if(!(n % 2)) {
        fac[cnt++] = 2;
        while(!(n % 2)) n >>= 1;
    }
    for(ll i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            n /= i;
            fac[cnt++] = i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 2) fac[cnt++] = n;
}

int main() {
    ll n, res;
    scanf("%lld", &n);
    res = n;
    factors(n);
    for(int i = 0; i < cnt; ++i) res = res / fac[i] * (fac[i] - 1);
    printf("%lld", res);
    return 0;
}
