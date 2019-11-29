#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> match;

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
    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y;
        cin >> n >> m;
        adj.clear(); adj.resize(m + 1);
        for(int i = 1; i <= m; ++i) {
            cin >> x >> y;
            for(int j = x; j <= y; ++j) adj[i].push_back(j);
        }
        int ans = 0;
        match.clear(); match.resize(n + 1);
        for(int i = 1; i <= m; ++i) {
            visited.clear(); visited.resize(m + 1);
            if(dfs(i)) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
