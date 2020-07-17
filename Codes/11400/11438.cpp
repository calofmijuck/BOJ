#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100050];
int depth[100050], parent[100050][21];
bool visited[100050];

void dfs(int v, int d) {
    visited[v] = true;
    depth[v] = d;
    for(int next : adj[v]) {
        if(visited[next]) continue;
        parent[next][0] = v;
        dfs(next, d + 1);
    }
}

void preprocess(int n) {
    parent[1][0] = 1;
    for(int j = 1; j <= 20; ++j) {
        for(int i = 1; i <= n; ++i)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) {
        int tmp = v; v = u; u = tmp;
    }
    int d = depth[u] - depth[v];
    int j = 0;
    while(d > 0) {
        if(d & 1)
            u = parent[u][j];
        j++;
        d >>= 1;
    }
    if(u == v)
        return u;
    while(parent[u][0] != parent[v][0]) {
        int j = 0;
        while(parent[u][j] != parent[v][j])
            j++;
        j--;
        u = parent[u][j];
        v = parent[v][j];
    }
    return parent[u][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    preprocess(n);
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}