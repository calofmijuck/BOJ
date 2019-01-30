#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10101];
bool visited[10101];
int ans[10101];

int dfs(int v) {
    visited[v] = true;
    int ret = 0;
    for(int e : adj[v]) {
        if(!visited[e]) ret += dfs(e) + 1;
    }
    return ret;
}

int main() {
    int n, m, x, y, mx = 0;
    vector<int> vec;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) {
        ans[i] = dfs(i);
        mx = max(mx, ans[i]);
        memset(visited, 0, sizeof(visited));
    }
    for(int i = 1; i <= n; ++i)
        if(ans[i] == mx) printf("%d ", i);
    return 0;
}
