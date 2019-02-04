#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INF 0x3fffffff

int v;
vector<pii> adj[505];

vector<int> bellmanFord(int src) {
    vector<int> dist(v + 1, INF);
    dist[src] = 0;
    bool updated;
    for(int it = 0; it < v; ++it) {
        updated = false;
        for(int i = 1; i <= v; ++i) {
            for(pii p : adj[i]) {
                int next = p.first, cost = p.second;
                if(dist[next] > dist[i] + cost) {
                    dist[next] = dist[i] + cost;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    if(updated) dist.clear();
    return dist;
}

int main() {
    int tc, m, w, s, e, t;
    vector<int> res;
    scanf("%d", &tc);
    while(tc--) {
        for(int i = 0; i < 505; ++i) adj[i].clear();
        scanf("%d %d %d", &v, &m, &w);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &s, &e, &t);
            adj[s].push_back({e, t});
            adj[e].push_back({s, t});
        }
        for(int i = 0; i < w; ++i) {
            scanf("%d %d %d", &s, &e, &t);
            adj[s].push_back({e, -t});
        }
        res = bellmanFord(1);
        if(res.empty() || res[1] < 0) puts("YES");
        else puts("NO");
    }
    return 0;
}
