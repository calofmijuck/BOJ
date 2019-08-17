#include <iostream>
using namespace std;
typedef pair<int, int> pii;

#define MAX_N 101010

pii tree[4 * MAX_N];

pii query(int left, int right, int node, int nodeLeft, int nodeRight) {
    if(right < nodeLeft || nodeRight < left) return {0x7FFFFFFF, 0x0};
    if(left <= nodeLeft && nodeRight <= right) return tree[node];
    int mid = (nodeLeft + nodeRight) / 2;
    pii lq = query(left, right, 2 * node, nodeLeft, mid);
    pii rq = query(left, right, 2 * node + 1, mid + 1, nodeRight);
    return {min(lq.first, rq.first), max(lq.second, rq.second)};
}

pii update(int idx, pii val, int node, int nodeLeft, int nodeRight) {
    if(idx < nodeLeft || nodeRight < idx) return tree[node];
    if(nodeLeft == nodeRight) return tree[node] = val;
    int mid = (nodeLeft + nodeRight) / 2;
    pii lu = update(idx, val, 2 * node, nodeLeft, mid);
    pii ru = update(idx, val, 2 * node + 1, mid + 1, nodeRight);
    return tree[node] = {min(lu.first, ru.first), max(lu.second, ru.second)};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, n, x;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        update(i, {x, x}, 1, 1, n);
    }
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pii q = query(a, b, 1, 1, n);
        cout << q.first << ' ' << q.second << '\n';
    }
}
