#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll arr[1010101];
ll tree[4 * 1010101];

ll init(ll left, ll right, ll node) {
    if(left == right) return tree[node] = arr[left];
    ll mid = (left + right) / 2;
    tree[node] = 1;
    tree[node] *= init(left, mid, node * 2);
    tree[node] %= MOD;
    tree[node] *= init(mid + 1, right, node * 2 + 1);
    tree[node] %= MOD;
    return tree[node];
}

ll query(ll left, ll right, ll node, ll nodeLeft, ll nodeRight) {
    if(right < nodeLeft || nodeRight < left) return 1;
    if(left <= nodeLeft && nodeRight <= right) return tree[node];
    ll mid = (nodeLeft + nodeRight) / 2;
    return (query(left, right, node * 2, nodeLeft, mid) * query(left, right, node * 2 + 1, mid + 1, nodeRight)) % MOD;
}

ll update(ll idx, ll x, ll node, ll nodeLeft, ll nodeRight) {
    if(idx < nodeLeft || idx > nodeRight) return tree[node];
    if(nodeLeft == nodeRight) return tree[node] = x;
    ll mid = (nodeLeft + nodeRight) / 2;
    return tree[node] = (update(idx, x, node * 2, nodeLeft, mid) * update(idx, x, node * 2 + 1, mid + 1, nodeRight)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    init(1, n, 1);
    for(int i = 0; i < k + m; ++i) {
        ll cmd, b, c;
        cin >> cmd >> b >> c;
        if(cmd == 1) {
            update(b, c, 1, 1, n);
        } else {
            cout << query(b, c, 1, 1, n) << '\n';
        }
    }
    return 0;
}
