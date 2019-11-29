// Bipartite Matching BOJ#1298
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[110];
bool visited[110];
int match[110];

bool dfs(int v) {
    if(visited[v]) return false;
    visited[v] = true;
    for(int next : adj[v]) {
        if(!match[next] || dfs(match[next])) {
            match[next] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        memset(visited, 0, sizeof(visited));
        if(dfs(i)) ret++;
    }
    cout << ret;
}