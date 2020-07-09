#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> pii;

vector<pii> adj[1010];

void dijkstra(int src, vector<int>& dist, vector<int>& path) {
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
				path[v] = here;
                dist[v] = nextdist;
                pq.push({-nextdist, v});
            }
        }
    }
}

void dijkstra(int src, int a, int b, vector<int>& dist) {
    dist[src] = 0;
    priority_queue<pii> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int cost = -pq.top().first, here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(pii p : adj[here]) {
			if((here == a && p.first == b) || (here == b && p.first == a)) continue;
            int v = p.first, nextdist = cost + p.second;
            if(dist[v] > nextdist) {
                dist[v] = nextdist;
                pq.push({-nextdist, v});
            }
        }
    }
}

int main() {
    int v, e, x, y, w;
    scanf("%d %d", &v, &e);
    for(int i = 0; i < e; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        adj[x].push_back({y, w});
		adj[y].push_back({x, w});
    }
	vector<int> ndist(1010, INF);
	vector<int> path(1010);
	dijkstra(1, ndist, path);
	int minTime = ndist[v], ans = 0;
	int curr = v;
	while(curr != 1) {
		vector<int> dist(1010, INF);
		dijkstra(1, curr, path[curr], dist);
		int t = dist[v];
		if(t == INF) {
			printf("-1");
			return 0;
		} else
			ans = max(ans, t - minTime);
		curr = path[curr];
	}
	cout << ans;
    return 0;
}
