#include <bits/stdc++.h>
using namespace std;

using graph_t = vector<vector<int>>;

bool visited[2000];

bool dfs(graph_t& graph, int v, int depth) {
    if (depth == 4) {
        return true;
    }

    bool exists = false;

    visited[v] = true;
    for (int next : graph[v]) {
        if (visited[next]) {
            continue;
        }

        visited[next] = true;
        exists |= dfs(graph, next, depth + 1);
    }
    visited[v] = false;
    return exists;
}

bool solve(graph_t& graph) {
    bool exists = false;
    for (int i = 0; i < (int) graph.size(); ++i) {
        exists |= dfs(graph, i, 0);
    }
    return exists;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    graph_t adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << solve(adj);
    return 0;
}
