#include <bits/stdc++.h>
using namespace std;

int gph[1010][1010];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(gph, 0x3f, sizeof(gph));
	int n, m, x;
	cin >> n >> m >> x;
	for(int i = 0; i < n; ++i) gph[i][i] = 0;
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		gph[u][v] = w;
	}
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j)
				gph[i][j] = min(gph[i][j], gph[i][k] + gph[k][j]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, gph[i][x] + gph[x][i]);
	cout << ans;
	return 0;
}