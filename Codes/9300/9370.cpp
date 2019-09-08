#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF 0x3f3f3f3f

vector<vector<pii>> gph;
int fromSt[2020], fromEdge[2020];

void dijkstra(int st, int* dist) {
    priority_queue<pii> pq;
    pq.push({0, st});
    while(!pq.empty()) {
        int here = pq.top().second, cost = -pq.top().first;
        pq.pop();
        if(dist[here] != INF) continue;
        dist[here] = cost;
        for(pii next : gph[here]) {
            if(dist[next.first] != INF) continue;
            pq.push({-cost - next.second, next.first});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        memset(fromSt, INF, sizeof(fromSt));
        memset(fromEdge, INF, sizeof(fromEdge));
        int n, m, t, s, g, h, a, b, d, x;
        cin >> n >> m >> t >> s >> g >> h;
        gph.clear();
        gph.resize(n + 1);
        for(int i = 0; i < m; ++i) {
            cin >> a >> b >> d;
            gph[a].push_back({b, d});
            gph[b].push_back({a, d});
        }
        dijkstra(s, fromSt);
        int edge = fromSt[g] < fromSt[h] ? h : g;
        dijkstra(edge, fromEdge);
        vector<int> query;
        for(int i = 0; i < t; ++i) {
            cin >> x;
            query.push_back(x);
        }
        sort(query.begin(), query.end());
        for(int v : query) {
            if(fromSt[v] == INF || fromEdge[v] == INF) continue;
            if(fromSt[v] == fromSt[edge] + fromEdge[v]) cout << v << ' ';
        }
        cout << '\n';
    }
}