#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10010];
int depth[10010], parent[10010][16];
bool visited[10010];

void dfs(int v, int d) {
    visited[v] = true;
    depth[v] = d;
    for(int next : adj[v]) {
        if(visited[next]) continue;
        parent[next][0] = v;
        dfs(next, d + 1);
    }
}

void preprocess(int n, int v) {
    parent[v][0] = 1;
    for(int j = 1; j < 16; ++j) {
        for(int i = 1; i <= n; ++i)
            parent[i][j] = parent[parent[i][j - 1]][j - 1]; 
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) {
        int tmp = v; v = u; u = tmp;
    }
    int d = depth[u] - depth[v];
    int j = 0;
    while(d > 0) {
        if(d & 1)
            u = parent[u][j];
        j++;
        d >>= 1;
    }
    if(u == v)
        return u;
    while(parent[u][0] != parent[v][0]) {
        int j = 0;
        while(parent[u][j] != parent[v][j])
            j++;
        j--;
        u = parent[u][j];
        v = parent[v][j];
    }
    return parent[u][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		memset(depth, 0, sizeof(depth));
		memset(visited, false, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		for(int i = 0; i < 10010; ++i)
			adj[i].clear();
		int n, m;
		cin >> n;
		bitset<10010> isChild(false);
		for(int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			isChild[v] = true;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int root = 0;
		for(int i = 1; i <= n; ++i) {
			if(!isChild[i]) { 
				root = i;
				break;
			}
		}
		dfs(root, 0);
		preprocess(n, root);
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
    return 0;
}