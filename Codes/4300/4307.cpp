#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t, l, n, in;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &l, &n);
        ll ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &in);
            ll tmp = min(l - in, in);
            ans1 = max(ans1, tmp);
            tmp = max(l - in, in);
            ans2 = max(ans2, tmp);
        }
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}
