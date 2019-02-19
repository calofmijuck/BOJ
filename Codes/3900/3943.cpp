#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t, n;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        ll mx = n;
        while(n != 1) {
            if(n % 2) n = 3 * n + 1;
            else n >>= 1;
            mx = max(mx, n);
        }
        printf("%lld\n", mx);
    }
    return 0;
}
