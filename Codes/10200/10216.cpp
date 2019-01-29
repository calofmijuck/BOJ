#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii loc[3030];
int rad[3030], ans, n;
bool graph[3030][3030], visited[3030];

int sq(int x) {
    return x * x;
}

bool adj(int i, int j) {
    int dsq = sq(loc[i].first - loc[j].first) + sq(loc[i].second - loc[j].second);
    int r = sq(rad[i] + rad[j]);
    return dsq <= r;
}

void dfs(int v) {
    visited[v] = true;
    for(int i = 0; i < n; i++) {
        if(graph[v][i] && !visited[i]) dfs(i);
    }
}

int main() {
    int t, a, b, r;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(graph, false, sizeof(graph));
        memset(visited, false, sizeof(visited));
        ans = 0;
        for(int i = 0; i < n; ++i) scanf("%d %d %d", &loc[i].first, &loc[i].second, &rad[i]);
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(adj(i, j)) graph[i][j] = graph[j][i] = true;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) ans++, dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
