#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, adjT;
vector<bool> visited;
vector<int> fin, scc;
int ftime, cnt;

void dfs(int v) {
    visited[v] = true;
    for(int next : adj[v])
        if(!visited[next]) dfs(next);
    fin[++ftime] = v;
}

void rdfs(int v) {
    visited[v] = true;
    scc[v] = cnt;
    for(int next : adjT[v])
        if(!visited[next]) rdfs(next);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        fin.clear(); fin.resize(n + 1);
        adj.clear(); adj.resize(n + 1);
        adjT.clear(); adjT.resize(n + 1);
        scc.clear(); scc.resize(n + 1);
        visited.clear(); visited.resize(n + 1);
        ftime = 0;
        int x, y;
        for(int i = 0; i < m; ++i) {
            cin >> x >> y;
            adj[x].push_back(y);
            adjT[y].push_back(x);
        }
        for(int i = 1; i <= n; ++i) {
            if(!visited[i]) dfs(i);
        }
        visited.clear(); visited.resize(n + 1);
        cnt = 0;
        for(int i = n; i > 0; --i) {
            int curr = fin[i];
            if(!visited[curr]) {
                cnt++;
                rdfs(curr);
            }
        }
        vector<int> indeg(cnt + 1, 0);
        for(int i = 1; i <= n; ++i) {
            for(int v : adj[i]) {
                if(scc[i] == scc[v]) continue;
                indeg[scc[v]]++;
            }
        }
        int ans = 0;
        for(int i = 1; i <= cnt; ++i) {
            if(indeg[i] == 0) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}