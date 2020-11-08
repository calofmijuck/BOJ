#include <bits/stdc++.h>
using namespace std;

int tree[400040];
vector<int> ans;

int update(int idx, int x, int node, int left, int right) {
    if(idx < left || right < idx)
        return tree[node];
    if(left == right)
        return tree[node] = x;
    int mid = (left + right) / 2;
    return tree[node] = update(idx, x, 2 * node, left, mid) + update(idx, x, 2 * node + 1, mid + 1, right);
}

int query(int k, int node, int left, int right) {
    if(left == right)
        return left;
    int mid = (left + right) / 2;
    if(k <= tree[2 * node])
        return query(k, 2 * node, left, mid);
    else
        return query(k - tree[2 * node], 2 * node + 1, mid + 1, right);
}

int sum_query(int low, int high, int node, int left, int right) {
    if(high < left || low > right)
        return 0;
    if(low <= left && right <= high)
        return tree[node];
    int mid = (left + right) / 2;
    return sum_query(low, high, 2 * node, left, mid) + sum_query(low, high, 2 * node + 1, mid + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        update(i, 1, 1, 1, n);
    int len = n - 1;
    ans.push_back(k);
    update(k, 0, 1, 1, n);
    for(int i = 2; i <= n; ++i) {
        int x = (sum_query(1, ans.back(), 1, 1, n) + k) % len;
        if(x == 0)
            x = len;
        int idx = query(x, 1, 1, n);
        ans.push_back(idx);
        update(idx, 0, 1, 1, n);
        --len;
    }
    cout << '<';
    for(int i = 0; i < (int) ans.size() - 1; ++i)
        cout << ans[i] << ", ";
    cout << ans.back() << '>';
    return 0;
}