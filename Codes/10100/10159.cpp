#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<bool>> graph;

graph adj;

void floyd_warshall(graph& graph, int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!graph[i][j]) {
                    graph[i][j] = graph[i][k] && graph[k][j];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        adj[i].resize(n + 1);
        adj[i][i] = true;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = true;
    }

    floyd_warshall(adj, n);

    for (int i = 1; i <= n; ++i) {
        int unknown = 0;
        for (int j = 1; j <= n; ++j) {
            if (!adj[i][j] && !adj[j][i]) {
                unknown++;
            }
        }
        cout << unknown << '\n';
    }
    return 0;
}
