#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> adj[1010];
priority_queue<int> dist[1010];

void dijkstra(int src, int k) {
    dist[src].push(0);
    priority_queue<pii> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int cost = -pq.top().first, curr = pq.top().second;
        pq.pop();
        for(pii p : adj[curr]) {
            int next = p.first, next_dist = cost + p.second;
            if(dist[next].size() < k || next_dist < dist[next].top()) {
                if(dist[next].size() == k) dist[next].pop();
                dist[next].push(next_dist);
                pq.push({-next_dist, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(1, k);
    for(int i = 1; i <= n; ++i) {
        if(dist[i].size() < k) cout << -1 << '\n';
        else cout << dist[i].top() << '\n';
    }
    return 0;
}