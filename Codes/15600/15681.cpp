#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100001];
int subtree[100001];
bool visited[100001];

int dfs(int v) {
    visited[v] = true;
    for (auto next : tree[v]) {
        if (!visited[next]) {
            subtree[v] += dfs(next);
        }
    }
    subtree[v] += 1;
    return subtree[v];
}

void solve(int n, int root, int queries) {
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(root);

    int q;
    for (int i = 0; i < queries; ++i) {
        cin >> q;
        cout << subtree[q] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, r, q;
    cin >> n >> r >> q;

    solve(n, r, q);
    return 0;
}
