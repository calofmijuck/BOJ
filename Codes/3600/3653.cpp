#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100010

int tree[8 * MAX_N], idx[MAX_N];

int update(int idx, int val, int node, int nodeLeft, int nodeRight) {
    if(idx < nodeLeft || nodeRight < idx) return tree[node];
    if(nodeLeft == nodeRight) return tree[node] = val;
    int mid = (nodeLeft + nodeRight) / 2;
    return tree[node] = update(idx, val, 2 * node, nodeLeft, mid) + update(idx, val, 2 * node + 1, mid + 1, nodeRight);
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
    if(left > nodeRight || right < nodeLeft) return 0;
    if(left <= nodeLeft && nodeRight <= right) return tree[node];
    int mid = (nodeLeft + nodeRight) / 2;
    return query(left, right, 2 * node, nodeLeft, mid) + query(left, right, 2 * node + 1, mid + 1, nodeRight);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n, m, x;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(tree, 0, sizeof(tree));
        memset(idx, 0, sizeof(idx));
        for(int i = m + 1; i <= n + m; ++i) {
            idx[i - m] = i;
            update(i, 1, 1, 1, n + m);
        }
        for(int i = 0; i < m; ++i) {
            cin >> x;
            cout << query(1, idx[x] - 1, 1, 1, n + m) << ' ';
            update(idx[x], 0, 1, 1, n + m);
            idx[x] = m - i;
            update(idx[x], 1, 1, 1, n + m);
        }
        cout << '\n';
    }    
    return 0;
}