#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1010];
bool visited[1010];
int match[1010];
int n;

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

int bipartite() {
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        memset(visited, 0, sizeof(visited));
        if(dfs(i)) ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, x, k;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        for(int j = 0; j < x; ++j) {
            cin >> k;
            adj[i].push_back(k);
        }
    }
    cout << bipartite();
}