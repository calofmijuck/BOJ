#include <bits/stdc++.h>
using namespace std;

vector<int> adj[110];
int dist[110];

int bfs(int v, int dst) {
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        if(curr == dst) return dist[curr];
        for(int next : adj[curr]) {
            if(dist[next]) continue;
            q.push(next);
            dist[next] = dist[curr] + 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, a, b, m, x, y;
    cin >> n >> a >> b >> m;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int res = bfs(a, b);
    cout << res;
    
    return 0;
}
