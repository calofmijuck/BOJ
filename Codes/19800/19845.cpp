#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll nemo[250005], rev[250005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> nemo[i];
        rev[n - i - 1] = nemo[i];
    }
    for(int i = 0; i < q; ++i) {
        ll x, y, ans = 0;
        cin >> x >> y;
        ans += max(0LL, nemo[y - 1] - x + 1);
        int idx = lower_bound(rev, rev + n, x) - rev;
        y = n - y;
        int r = y - idx;
        if(idx <= y)
            ans += r;
        cout << ans << '\n';
    }
    return 0;
}