#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INF 0x6fffffff

vector<pii> adj[20202];
vector<int> dist(20202, INF);

void dijkstra(int src) {
    dist[src] = 0;
    priority_queue<pii> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int cost = -pq.top().first, here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(pii p : adj[here]) {
            int v = p.first, nextdist = cost + p.second;
            if(dist[v] > nextdist) {
                dist[v] = nextdist;
                pq.push({-nextdist, v});
            }
        }
    }
}

int main() {
    int v, e, st, x, y, w;
    scanf("%d %d %d", &v, &e, &st);
    for(int i = 0; i < e; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        adj[x].push_back({y, w});
    }
    dijkstra(st);
    for(int i = 1; i <= v; ++i) {
        if(dist[i] == INF) puts("INF");
        else printf("%d\n", dist[i]);
    }
    return 0;
}
