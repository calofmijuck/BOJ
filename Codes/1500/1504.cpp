#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INF 0xfffffff

vector<pii> adj[808];

vector<int> dijkstra(int src) {
    vector<int> dist(808, INF);
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
    return dist;
}

int main() {
    int n, e, src, dst, x, y, w;
    scanf("%d %d", &n, &e);
    for(int i = 0; i < e; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    scanf("%d %d", &src, &dst);
    vector<int> d1 = dijkstra(src), d2 = dijkstra(dst);
    int ans1 = d1[1] + d1[dst] + d2[n], ans2 = d2[1] + d2[src] + d1[n];
    int ret = min(ans1, ans2);
    if(ret >= INF) printf("-1");
    else printf("%d", ret);
    return 0;
}
