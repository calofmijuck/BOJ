#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1010], tsort;
bool visited[1010], added[1010], none;

void dfs(int v) {
	visited[v] = true;
	for(int u : adj[v]) {
		if(!visited[u]) dfs(u);
		else if(!added[u]) none = 1;
	}
	tsort.push_back(v);
	added[v] = true;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int k, prev = 0;
		scanf("%d", &k);
		for(int j = 0; j < k; ++j) {
			int x;
			scanf("%d", &x);
			if(prev != 0)
				adj[prev].push_back(x);
			prev = x;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(!visited[i]) dfs(i);
	}
	if(none) {
		printf("0");
		return 0;
	}
	for(int i = n - 1; i >= 0; --i) {
		printf("%d\n", tsort[i]);
	}
	return 0;
}