#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INF 0x7FFFFFFF

int n, m, st, ed, w;
vector<pii> adj[1001];

vector<int> dijkstra(int v) {
    vector<int> dist(n + 1, INF);
    dist[v] = 0;
    priority_queue<pii> pq;
    pq.push({v, 0});
    while(!pq.empty()) {
        pii tmp = pq.top(); pq.pop();
        int curr = tmp.first, cost = -tmp.second;
        if(dist[curr] < cost) continue;
        for(pii p : adj[curr]) {
            int next = p.first, ncost = cost + p.second;
            if(dist[next] > ncost) {
                dist[next] = ncost;
                pq.push({next, -ncost});
            }
        }
    }
    return dist;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &st, &ed, &w);
        adj[st].push_back({ed, w});
    }
    scanf("%d %d", &st, &ed);
    vector<int> res = dijkstra(st);
    printf("%d", res[ed]);
    return 0;
}
