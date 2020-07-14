#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

typedef long long ll;

int num[MAX_N + 5], tree[4 * MAX_N], small[MAX_N + 5], large[MAX_N + 5];
ll ans = 0;

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
    if(right < nodeLeft || left > nodeRight) return 0;
    if(left <= nodeLeft && nodeRight <= right) return tree[node];
    ll mid = (nodeLeft + nodeRight) / 2;
    return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
}

int update(int idx, int x, int node, int nodeLeft, int nodeRight) {
    if(idx < nodeLeft || nodeRight < idx) return tree[node];
    if(nodeLeft == nodeRight) return tree[node] += x;
    int mid = (nodeLeft + nodeRight) / 2;
    return tree[node] = update(idx, x, node * 2, nodeLeft, mid) + update(idx, x, node * 2 + 1, mid + 1, nodeRight);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> num[i];
    for(int i = n; i >= 0; --i) {
        small[i] = query(1, num[i] - 1, 1, 1, MAX_N);
        update(num[i], 1, 1, 1, MAX_N);
    }
    memset(tree, 0, sizeof(tree));
    for(int i = 1; i <= n; ++i) {
        large[i] = query(num[i] + 1, MAX_N, 1, 1, MAX_N);
        update(num[i], 1, 1, 1, MAX_N);
    }
    for(int i = 1; i <= n; ++i)
        ans += (ll) small[i] * large[i];
    cout << ans;
    return 0;
}
