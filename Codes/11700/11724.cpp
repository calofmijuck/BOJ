#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1010];
bool visited[1010];

void bfs(int v) {
    visited[v] = true;
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int next : adj[curr]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, x, y, ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            bfs(i);
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
