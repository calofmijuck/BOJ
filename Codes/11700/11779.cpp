#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> pii;

int n, m, src, dst;
vector<pii> adj[1010];
vector<pii> dist(1010, make_pair(INF, 0));

void dijkstra(int src) {
	dist[src].first = 0;
	priority_queue<pii> pq;
	pq.push({0, src});
	while(!pq.empty()) {
		int cost = -pq.top().first, here = pq.top().second;
		pq.pop();
		if(dist[here].first < cost) continue;
		for(pii p : adj[here]) {
			int v = p.first, nextdist = cost + p.second;
			if(dist[v].first > nextdist) {
				dist[v].first = nextdist;
				dist[v].second = here;
				pq.push({-nextdist, v});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
	}
	cin >> src >> dst;
	dijkstra(src);
	cout << dist[dst].first << '\n';
	int curr = dst;
	stack<int> st;
	st.push(curr);
	while(curr != src) {
		curr = dist[curr].second;
		st.push(curr);
	}
	cout << st.size() << '\n';
	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;
}