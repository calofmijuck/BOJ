#include <bits/stdc++.h>
using namespace std;

#define MAX_N 250020

int tree[4 * MAX_N], arr[MAX_N];

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
    int n, k, x;
    cin >> n >> k;
    int idx = (k + 1) / 2;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < k; ++i) update(arr[i], 1, 1, 0, MAX_N);
    long long sum = 0;
    for(int i = k; i < n + 1; ++i) {
        sum += query(idx, 1, 0, MAX_N);
        update(arr[i - k], -1, 1, 0, MAX_N);
        update(arr[i], 1, 1, 0, MAX_N);
    }
    cout << sum;
    return 0;
}