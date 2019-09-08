#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2000020

int tree[4 * MAX_N];

int update(int idx, int val, int node, int nodeLeft, int nodeRight) {
    if(idx < nodeLeft || nodeRight < idx) return tree[node];
    if(nodeLeft == nodeRight) return tree[node] += val;
    int mid = (nodeLeft + nodeRight) / 2;
    return tree[node] = update(idx, val, 2 * node, nodeLeft, mid) + update(idx, val, 2 * node + 1, mid + 1, nodeRight);
}

int query(int right, int node, int nodeLeft, int nodeRight) {
    if(nodeLeft == nodeRight) return nodeLeft;
    else {
        int mid = (nodeLeft + nodeRight) / 2;
        if(right <= tree[2 * node]) return query(right, 2 * node, nodeLeft, mid);
        else return query(right - tree[2 * node], 2 * node + 1, mid + 1, nodeRight);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, t, x;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> t >> x;
        if(t == 1) update(x, 1, 1, 1, MAX_N);
        else {
            int k = query(x, 1, 1, MAX_N);
            update(k, -1, 1, 1, MAX_N);
            cout << k << '\n';
        }
    }
    return 0;
}