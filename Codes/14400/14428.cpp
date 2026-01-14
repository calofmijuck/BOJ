#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100100;

ll arr[MAX_N] = { INT_MAX };
ll tree[4 * MAX_N];

ll init(ll left, ll right, ll node) {
    if (left == right) {
        return tree[node] = left;
    }

    ll mid = (left + right) / 2;
    ll min_left = init(left, mid, node * 2);
    ll min_right = init(mid + 1, right, node * 2 + 1);
    return tree[node] = (arr[min_left] <= arr[min_right]) ? min_left : min_right;
}

ll query(ll left, ll right, ll node, ll nodeLeft, ll nodeRight) {
    if (right < nodeLeft || nodeRight < left) {
        return 0;
    }

    if (left <= nodeLeft && nodeRight <= right) {
        return tree[node];
    }

    ll mid = (nodeLeft + nodeRight) / 2;
    ll min_left = query(left, right, node * 2, nodeLeft, mid);
    ll min_right = query(left, right, node * 2 + 1, mid + 1, nodeRight);
    return (arr[min_left] <= arr[min_right]) ? min_left : min_right;
}

ll update(ll idx, ll x, ll node, ll nodeLeft, ll nodeRight) {
    if (idx < nodeLeft || idx > nodeRight) {
        return tree[node];
    }

    if (nodeLeft == nodeRight) {
        arr[idx] = x;
        return idx;
    }

    ll mid = (nodeLeft + nodeRight) / 2;
    ll min_left = update(idx, x, node * 2, nodeLeft, mid);
    ll min_right = update(idx, x, node * 2 + 1, mid + 1, nodeRight);
    return tree[node] = (arr[min_left] <= arr[min_right]) ? min_left : min_right;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    init(1, n, 1);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        ll cmd, b, c;
        cin >> cmd >> b >> c;
        if (cmd == 1) {
            update(b, c, 1, 1, n);
        } else {
            cout << query(b, c, 1, 1, n) << '\n';
        }
    }
    return 0;
}
