#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

#define all(x) (x).begin(), (x).end()
#define pb push_back


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, w, t, s;
    cin >> n >> w;
    vl g3, g5;
    for(int i = 0; i < n; ++i) {
        cin >> t >> s;
        if(t == 3) {
            g3.pb(s);
        } else {
            g5.pb(s);
        }
    }
    sort(all(g3), greater<ll>());
    sort(all(g5), greater<ll>());
    for(int i = 1; i < g3.size(); ++i) {
        g3[i] += g3[i - 1];
    }
    for(int i = 1; i < g5.size(); ++i) {
        g5[i] += g5[i - 1];
    }
    ll ans = 0;
    for(int x = 0; x <= w / 3; ++x) {
        ll total = 0;
        int y = (w - 3 * x) / 5;
        if(x != 0 && g3.size() != 0) {
            total += g3[min((int) g3.size() - 1, x - 1)];
        }
        if(y != 0 && g5.size() != 0) {
            total += g5[min((int) g5.size() - 1, y - 1)];
        }
        ans = max(ans, total);
    }
    cout << ans;
}
