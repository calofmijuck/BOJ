#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& tree, int n, int m) {
    vector<int> sum(n + 1, 0);

    int employee, amount;
    for (int i = 0; i < m; ++i) {
        cin >> employee >> amount;
        sum[employee] += amount;
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int child : tree[curr]) {
            q.push(child);
            sum[child] += sum[curr];
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << sum[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int parent;

    vector<vector<int>> tree(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> parent;
        if (parent == -1) {
            continue;
        }

        tree[parent].push_back(i);
    }

    solve(tree, n, m);
    return 0;
}
