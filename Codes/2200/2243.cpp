#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000010

int tree[4 * MAX_N];

int update(int idx, int val, int node, int nodeLeft, int nodeRight) {
    if(idx < nodeLeft || nodeRight < idx) return tree[node];
    if(nodeLeft == nodeRight) return tree[node] += val;
    int mid = (nodeLeft + nodeRight) / 2;
    return tree[node] = update(idx, val, 2 * node, nodeLeft, mid) + update(idx, val, 2 * node + 1, mid + 1, nodeRight);
}

int query(int k, int node, int nodeLeft, int nodeRight) {
    if(nodeLeft == nodeRight) return nodeLeft;
    int mid = (nodeLeft + nodeRight) / 2;
    if(k <= tree[2 * node]) return query(k, 2 * node, nodeLeft, mid);
    else return query(k - tree[2 * node], 2 * node + 1, mid + 1, nodeRight);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, a, b, c;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        if(a == 1) {
            cin >> b;
            int k = query(b, 1, 1, MAX_N);
            cout << k << '\n';
            update(k, -1, 1, 1, MAX_N);
        } else if(a == 2) {
            cin >> b >> c;
            update(b, c, 1, 1, MAX_N);
        }
    }
}