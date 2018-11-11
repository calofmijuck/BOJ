#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<1001001> isMultiple;

int main() {
    ll min, max;
    scanf("%lld %lld", &min, &max);
    for(ll p = 2; p <= 1000000; ++p) {
        ll div = p * p;
        for(ll j = (min + div - 1) / div * div; j <= max; j += div)
            isMultiple[j - min] = true;
    }
    ll ans = max - min + 1, cnt = 0;
    for(ll i = 0; i < ans; ++i) {
        if(!isMultiple[i]) cnt++;
    }
    printf("%lld", cnt);
    return 0;
}
