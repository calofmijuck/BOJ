#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int items[105], gph[105][105];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(gph, 0x3f, sizeof(gph));
	int n, m, r, x, y, w;
	cin >> n >> m >> r;
	for(int i = 1; i <= n; ++i)
		cin >> items[i];
	for(int i = 0; i < r; ++i) {
		cin >> x >> y >> w;
		gph[x][y] = gph[y][x] = w;
	}
	for(int i = 1; i <= n; ++i)
		gph[i][i] = 0;
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j)
				gph[i][j] = min(gph[i][j], gph[i][k] + gph[k][j]);
		}
	}
	int ans = 0;
	for(int l = 1; l <= n; ++l) {
		int curr = 0;
		for(int i = 1; i <= n; ++i) {
			if(gph[l][i] <= m)
				curr += items[i];
		}
		ans = max(ans, curr);
	}
	cout << ans;
	return 0;
}