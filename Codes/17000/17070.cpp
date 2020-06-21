#include <bits/stdc++.h>
using namespace std;

int dp[20][20][3], house[20][20];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			cin >> house[i][j];
	}
	dp[0][1][0] = 1;
	for(int j = 2; j < n; ++j) {
		if(house[0][j] == 1) continue;
		dp[0][j][0] = dp[0][j - 1][0];
	}
	for(int i = 1; i < n; ++i) {
		for(int j = 2; j < n; ++j) {
			if(house[i][j] == 1) continue;
			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
			if(!house[i - 1][j] && !house[i][j - 1])
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
		}
	}
	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
	return 0;
}
