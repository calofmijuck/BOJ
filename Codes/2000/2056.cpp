#include <bits/stdc++.h>
using namespace std;

int t[10010];
vector<int> adj[10010], res, dist(10010);
bool visited[10010];

void dfs(int v) {
	visited[v] = true;
	for(int e : adj[v]) {
		if(!visited[e]) dfs(e);
	}
	res.push_back(v);
}

int main() {
    int n, k, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", t + i, &k);
		for(int j = 0; j < k; ++j) {
			int x;
			scanf("%d", &x);
			adj[x].push_back(i);
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(!visited[i]) dfs(i);
	}
	for(int i = res.size() - 1; i >= 0; --i) {
		int curr = res[i];
		dist[curr] += t[curr];
		for(int v : adj[curr])
			dist[v] = max(dist[v], dist[curr]);
	}
	for(int i = 1; i <= n; ++i)
		ans = max(ans, dist[i]);
	printf("%d", ans);
	return 0;
}
