#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> pii;

vector<pii> gph[1010], rgph[1010];
vector<int> dist(1010, INF), rdist(1010, INF);

void dijkstra(vector<pii>* adj, vector<int>& dist, int src) {
	dist[src] = 0;
	priority_queue<pii> pq;
	pq.push({0, src});
	while(!pq.empty()) {
		int cost = -pq.top().first, here = pq.top().second;
		pq.pop();
		if(dist[here] < cost) continue;
		for(pii p : adj[here]) {
			int v = p.first, next = cost + p.second;
			if(dist[v] > next) {
				dist[v] = next;
				pq.push({-next, v});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, x;
	cin >> n >> m >> x;
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		gph[u].push_back({v, w});
		rgph[v].push_back({u, w});
	}
	dijkstra(gph, dist, x);
	dijkstra(rgph, rdist, x);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, dist[i] + rdist[i]);
	cout << ans;
	return 0;
}