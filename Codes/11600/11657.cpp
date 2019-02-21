#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 0x3fffffffffffffff;

int v;
vector<pii> adj[505];

vector<ll> bellmanFord(int src) {
    vector<ll> dist(v + 1, INF);
    dist[src] = 0;
    bool updated;
    for(int it = 0; it < v; ++it) {
        updated = false;
        for(int i = 1; i <= v; ++i) {
            for(pii p : adj[i]) {
                int next = p.first, cost = p.second;
                if(dist[i] != INF && dist[next] > dist[i] + cost) {
                    dist[next] = dist[i] + cost;
                    updated = true;
                    if(it == v) {
                        dist.clear();
                        return dist;
                    }
                }
            }
        }
        if(!updated) break;
    }
    if(updated) dist.clear();
    return dist;
}

int main() {
    int m, a, b, c;
    scanf("%d %d", &v, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({b, c});
    }
    vector<ll> res = bellmanFord(1);
    if(res.empty()) puts("-1");
    else for(int i = 2; i <= v; ++i) {
        printf("%lld\n", res[i] == INF ? -1 : res[i]);
    }
    return 0;
}
