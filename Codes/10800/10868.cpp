#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100010
#define INF 0x3f3f3f3f

int tree[4 * MAX_N];
int n, m, x;

int update(int idx, int val, int node, int nodeLeft, int nodeRight) {
    if(idx < nodeLeft || idx > nodeRight) return tree[node];
    if(nodeLeft == nodeRight) return tree[node] = val;
    int mid = (nodeLeft + nodeRight) / 2;
    return tree[node] = min(update(idx, val, 2 * node, nodeLeft, mid), update(idx, val, 2 * node + 1, mid + 1, nodeRight));
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
    if(nodeRight < left || right < nodeLeft) return INF;
    if(left <= nodeLeft && nodeRight <= right) return tree[node];
    int mid = (nodeLeft + nodeRight) / 2;
    return min(query(left, right, 2 * node, nodeLeft, mid), query(left, right, 2 * node + 1, mid + 1, nodeRight));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        update(i, x, 1, 1, n);
    }
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b, 1, 1, n) << '\n';
    }
    return 0;
}