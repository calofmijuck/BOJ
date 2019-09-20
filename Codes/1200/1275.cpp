#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 100010

ll tree[4 * MAX_N]; 

ll update(ll idx, ll val, ll node, ll nodeLeft, ll nodeRight) {
    if(idx < nodeLeft || idx > nodeRight) return tree[node];
    if(nodeLeft == nodeRight) return tree[node] = val;
    ll mid = (nodeLeft + nodeRight) / 2;
    return tree[node] = update(idx, val, 2 * node, nodeLeft, mid) + update(idx, val, 2 * node + 1, mid + 1, nodeRight);
}

ll query(ll left, ll right, ll node, ll nodeLeft, ll nodeRight) {
    if(right < nodeLeft || left > nodeRight) return 0;
    if(left <= nodeLeft && nodeRight <= right) return tree[node];
    ll mid = (nodeLeft + nodeRight) / 2;
    return query(left, right, 2 * node, nodeLeft, mid) + query(left, right, 2 * node + 1, mid + 1, nodeRight); 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, q, x;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        update(i, x, 1, 1, n);
    }
    for(int i = 0; i < q; ++i) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        cout << query(x, y, 1, 1, n) << '\n';
        update(a, b, 1, 1, n);
    }
    return 0;
}