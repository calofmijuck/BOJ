#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[1010], b[1010];
vector<int> pa, pb;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    int n, m;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    for(int i = 0; i < n; ++i) {
        int s = a[i];
        pa.push_back(s);
        for(int j = i + 1; j < n; ++j) {
            s += a[j];
            pa.push_back(s);
        }
    }
    for(int i = 0; i < m; ++i) {
        int s = b[i];
        pb.push_back(s);
        for(int j = i + 1; j < m; ++j) {
            s += b[j];
            pb.push_back(s);
        }
    }
    sort(pa.begin(), pa.end());
    sort(pb.begin(), pb.end());
    int l = 0, r = pb.size() - 1;
    ll ans = 0;
    while(true) {
        ll k = pa[l] + pb[r];
        if(k == t) {
            int p1 = l, p2 = r, cnt1 = 0, cnt2 = 0;
            while(p1 < pa.size() && pa[l] == pa[p1]) {
                p1++;
                cnt1++;
            }
            while(p2 >= 0 && pb[r] == pb[p2]) {
                p2--;
                cnt2++;
            }
            ans += (ll) cnt1 * cnt2;
            l = p1;
            r = p2;
        } else if(k < t) {
            l++;
        } else {
            r--;
        }
        if(l >= pa.size() || r < 0)
            break;
    }
    cout << ans;
    return 0;
}