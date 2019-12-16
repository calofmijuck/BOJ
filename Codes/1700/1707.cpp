#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vector<bool> visited;
vi check;

bool dfs(int v, int mark) {
    visited[v] = true;
    check[v] = mark;
    int nextMark = (mark == 1) ? 2 : 1;
    for(int next : adj[v]) {
        if(!visited[next]) {
            if(!dfs(next, nextMark)) return false;
        } else if(check[next] == mark) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k, v, e, x, y;
    cin >> k;
    while(k--) {
        cin >> v >> e;
        adj.clear(); adj.resize(v + 1);
        check.clear(); check.resize(v + 1);
        visited.clear(); visited.resize(v + 1);
        for(int i = 0; i < e; ++i) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool res = false;
        for(int i = 1; i <= v; ++i) {
            if(check[i] == 0) res = dfs(i, 1);
            if(!res) break;
        }
        if(!res) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
