#include <bits/stdc++.h>
using namespace std;

string mp[1001];
int dp[1001][1001][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n, k;
	cin >> m >> n >> k;
	for(int i = 1; i <= m; ++i) {
		cin >> mp[i];
		mp[i].insert(mp[i].begin(), ' ');
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			char c = mp[i][j];
			int idx = (c == 'J') ? 0 : ((c == 'O') ? 1 : 2);
			for(int k = 0; k < 3; ++k) 
				dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k] + (k == idx);
		}
	}
	int a, b, c, d;
	for(int i = 0; i < k; ++i) {
		cin >> a >> b >> c >> d;
		int ans[3];
		for(int k = 0; k < 3; ++k)
			ans[k] = dp[c][d][k] - dp[a - 1][d][k] - dp[c][b - 1][k] + dp[a - 1][b - 1][k];
		cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
	}
	return 0;
}