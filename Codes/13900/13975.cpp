#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            pq.push(x);
        }
        ll ans = 0;
        while(!pq.empty()) {
            ll u = pq.top(); pq.pop();
            ll v = pq.top(); pq.pop();
            ans += u + v;
            if(pq.empty())
                break;
            pq.push(u + v);
        }
        cout << ans << '\n';
    } 
    return 0;
}