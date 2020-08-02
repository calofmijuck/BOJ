#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
bool visited[100010];
int n, s, d, h, ans = 0;

int dfs(int v, int depth) {
	visited[v] = true;
	int maxDepth = depth;
	for(int next : adj[v]) {
		if(!visited[next])
			maxDepth = max(maxDepth, dfs(next, depth + 1));
	}
	if(maxDepth - depth >= d && v != s)
		ans += 2;
	return maxDepth;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s >> d;
	for(int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(s, 0);
	cout << ans;
	return 0;
}