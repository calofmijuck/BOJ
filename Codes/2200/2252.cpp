#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32010];
bool visited[32010];
stack<int> ans;

void dfs(int v) {
    visited[v] = true;
    for(auto w : adj[v]) {
        if(!visited[w]) dfs(w);
    }
    ans.push(v);
}

int main() {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
    }
    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) dfs(i);
    }
    while(!ans.empty()) {
        printf("%d ", ans.top());
        ans.pop();
    }
    return 0;
}
