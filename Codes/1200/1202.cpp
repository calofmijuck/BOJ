#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, k, x, y, ans = 0;
    cin >> n >> k;
    vector<pll> vec;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        vec.push_back({y, x});
    }
    sort(vec.begin(), vec.end());
    multiset<ll> ms;
    for(int i = 0; i < k; ++i) {
        cin >> x;
        ms.insert(x);
    }
    for(int i = n - 1; i >= 0; --i) {
        int c = vec[i].first, w = vec[i].second;
        multiset<ll>::iterator it = ms.lower_bound(w);
        if(it == ms.end())
            continue;
        ms.erase(it);
        ans += c;
    }
    cout << ans;
    return 0;
}
