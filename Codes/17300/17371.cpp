#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> vec;

ll dist(pll p1, pll p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) *(p1.second - p2.second);
}

int main() {
    int n;
    cin >> n;
    ll x, y;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        vec.push_back({x, y});
    }
    ll mi = 0x3ffffffffffff;
    pll ans;
    for(int i = 0; i < n; ++i) {
        ll m = 0;
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            ll d = dist(vec[i], vec[j]);
            m = max(m, d);
        }
        if(mi > m) {
            ans = vec[i];
            mi = m;
        }
    }
    cout << ans.first << ' ' << ans.second;
    return 0;
}
