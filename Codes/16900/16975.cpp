#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 1000100

ll tree[4 * MAX_N];
int arr[MAX_N];

ll query(ll left, ll right, ll node, ll nodeLeft, ll nodeRight) {
    if(right < nodeLeft || left > nodeRight) return 0;
    if(left <= nodeLeft && nodeRight <= right) return tree[node];
    ll mid = (nodeLeft + nodeRight) / 2;
    return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
}

ll update(ll idx, ll x, ll node, ll nodeLeft, ll nodeRight) {
    if(idx < nodeLeft || nodeRight < idx) return tree[node];
    if(nodeLeft == nodeRight) return tree[node] += x;
    ll mid = (nodeLeft + nodeRight) / 2;
    return tree[node] = update(idx, x, node * 2, nodeLeft, mid) + update(idx, x, node * 2 + 1, mid + 1, nodeRight);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        update(i, arr[i] - arr[i - 1], 1, 1, n);
    }
	cin >> m;
    for(int i = 0; i < m; ++i) {
        ll cmd, b, c;
        cin >> cmd;
        if(cmd == 1) {
			cin >> b >> c >> x;
			update(b, x, 1, 1, n);
			if(c != n) update(c + 1, -x, 1, 1, n);
		}
        else {
			cin >> b;
			cout << query(1, b, 1, 1, n) << '\n';
		}
    }
    return 0;
}
