#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int gph[1001][1001];
int godula[1001];
map<pii, pii> penalty;

vector<int> dijkstra(int n, int k, int src) {
    vector<int> dist(n + 1, 0x3f3f3f3f);
    dist[src] = k;
    priority_queue<pii> pq;
    pq.push({-k, src});
    while(!pq.empty()) {
        pii p = pq.top(); pq.pop();
        int cost = -p.first, curr = p.second;
        if(dist[curr] < cost) continue;
        for(int next = 1; next <= n; ++next) {
            if(gph[curr][next] == 0) continue;
            int nextdist = cost + gph[curr][next];
            if(penalty.find({curr, next}) != penalty.end()) {
                pii range = penalty[{curr, next}];
                if(range.first <= cost && cost <= range.second)
                    nextdist = range.second + gph[curr][next];
            }
            if(nextdist < dist[next]) {
                dist[next] = nextdist;
                pq.push({-nextdist, next});
            }
        }
    }
    return dist;
}

int main() {
    int n, m, a, b, k, g;
    scanf("%d %d %d %d %d %d", &n, &m, &a, &b, &k, &g);
    for(int i = 0; i < g; ++i)
        scanf("%d", &godula[i]);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        gph[u][v] = gph[v][u] = w;
    }
    int curr = godula[0], t = 0;
    for(int i = 1; i < g; ++i) {
        int next = godula[i];
        int next_t = t + gph[curr][next];
        penalty[{curr, next}] = {t, next_t};
        penalty[{next, curr}] = {t, next_t};
        t = next_t;
        curr = next;
    }
    vector<int> dist = dijkstra(n, k, a);
    printf("%d", dist[b] - k);
    return 0;
}