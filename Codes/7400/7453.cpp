#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[4004], b[4004], c[4004], d[4004];
vector<int> s, t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            s.push_back(a[i] + b[j]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            t.push_back(c[i] + d[j]);
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int l = 0, r = t.size() - 1;
    ll ans = 0;
    while(true) {
        ll k = s[l] + t[r];
        if(k == 0) {
            int p1 = l, p2 = r, cnt1 = 0, cnt2 = 0;
            while(p1 < s.size() && s[p1] == s[l]) {
                p1++;
                cnt1++;
            }
            while(p2 >= 0 && t[p2] == t[r]) {
                p2--;
                cnt2++;
            }
            ans += (ll) cnt1 * cnt2;
            l = p1;
            r = p2;
        } else if(k < 0) {
            l++;
        } else {
            r--;
        }
        if(l >= s.size() || r < 0)
            break;
    }
    cout << ans;
    return 0;
}