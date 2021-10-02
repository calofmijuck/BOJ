#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50050

vector<int> adj[MAX_N];
int node_depth[MAX_N], parent[MAX_N][20];
bool visited[MAX_N];

void dfs(int current, int depth) {
    visited[current] = true;
    node_depth[current] = depth;
    for (int next : adj[current]) {
        if (visited[next]) {
            continue;
        }
        parent[next][0] = current;
        dfs(next, depth + 1);
    }
}

void preprocess(int n) {
    parent[1][0] = 1;
    for (int j = 1; j < 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (node_depth[u] < node_depth[v]) {
        swap(u, v);
    }

    int diff = node_depth[u] - node_depth[v];
    int power = 0;
    while (diff > 0) {
        if (diff & 1) {
            u = parent[u][power];
        }
        power++;
        diff >>= 1;
    }

    if (u == v) {
        return u;
    }

    while (parent[u][0] != parent[v][0]) {
        int power = 0;
        while (parent[u][power] != parent[v][power]) {
            power++;
        }
        power--;
        u = parent[u][power];
        v = parent[v][power];
    }
    return parent[u][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    preprocess(n);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}
