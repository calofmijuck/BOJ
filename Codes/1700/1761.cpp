#include <bits/stdc++.h>
using namespace std;

#define MAX_N 40004

typedef pair<int, int> pii;

vector<pii> adj[MAX_N];
int node_depth[MAX_N];
bool visited[MAX_N];
int parent[MAX_N][17], dist[MAX_N][17];

void dfs(int current, int depth) {
    visited[current] = true;
    node_depth[current] = depth;
    for (pii next : adj[current]) {
        if (visited[next.first]) {
            continue;
        }
        parent[next.first][0] = current;
        dist[next.first][0] = next.second;
        dfs(next.first, depth + 1);
    }
}

void preprocess(int n) {
    parent[1][0] = 1;
    dist[1][0] = 0;
    for (int j = 1; j < 17; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            dist[i][j] = dist[i][j - 1] + dist[parent[i][j - 1]][j - 1];
        }
    }
}

int node_distance(int u, int v) {
    if (node_depth[u] < node_depth[v]) {
        swap(u, v);
    }

    int distance = 0;
    int diff = node_depth[u] - node_depth[v];
    int power = 0;
    while (diff > 0) {
        if (diff & 1) {
            distance += dist[u][power];
            u = parent[u][power];
        }
        power++;
        diff >>= 1;
    }

    if (u == v) {
        return distance;
    }

    while (parent[u][0] != parent[v][0]) {
        int power = 0;
        while (parent[u][power] != parent[v][power]) {
            power++;
        }
        power--;
        distance += dist[u][power] + dist[v][power];
        u = parent[u][power];
        v = parent[v][power];
    }
    distance += dist[u][0] + dist[v][0];
    return distance;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 0);
    preprocess(n);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        cout << node_distance(u, v) << '\n';
    }
    return 0;
}
