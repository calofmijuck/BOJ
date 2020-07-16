// Lowest Common Ancestor O(mlogn) refer to #11437

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[50050];
int depth[50050], parent[50050][20];
bool visited[50050];

void dfs(int v, int d) { // dfs with depth
    visited[v] = true;
    depth[v] = d; // mark depth
    for(int next : adj[v]) {
        if(visited[next]) continue;
        parent[next][0] = v; // 2^0-parent of vertex next is the current vertex v
        dfs(next, d + 1);
    }
}

void preprocess(int n) {
    parent[1][0] = 1; // parent of root as root
    for(int j = 1; j < 20; ++j) {
        for(int i = 1; i <= n; ++i)
            parent[i][j] = parent[parent[i][j - 1]][j - 1]; 
        // 2^j parent of i is equal to 2^(j-1) parent of [2^(j-1) parent of i]
        // 2^(j-1) + 2^(j-1) = 2^j
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) {
        int tmp = v; v = u; u = tmp;
    }
    int d = depth[u] - depth[v]; // find depth difference
    int j = 0;
    while(d > 0) { // move to same depth
        if(d & 1)
            u = parent[u][j];
        j++;
        d >>= 1;
    }
    if(u == v) // if same, return
        return u;
    while(parent[u][0] != parent[v][0]) {
        int j = 0;
        while(parent[u][j] != parent[v][j]) // go up the tree to find matching parent
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
    cin >> n; // number of vertices
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v; // edges
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0); // with node 1 as root
    preprocess(n); // find 2^k-parents
    cin >> m; // m queries
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}