#include <bits/stdc++.h>
using namespace std;

int profit[51][51], dp[51][51];

int sum(int x1, int y1, int x2, int y2) {
	return dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j)
			scanf("%d", &profit[i][j]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + profit[i][j];
	}
	
	int ans = 0;
	for(int i = 2; i <= n; ++i) {
		for(int j = 2; j <= n; ++j) {
			unordered_map<int, int> mp;
			for(int x = 1; x < i; ++x) {
				for(int y = 1; y < j; ++y)
					mp[sum(x, y, i - 1, j - 1)]++;
			}

			for(int x = i; x <= n; ++x) {
				for(int y = j; y <= n; ++y)
					ans += mp[sum(i, j, x, y)];
			}

			mp.clear();

			for(int x = 1; x < i; ++x) {
				for(int y = j; y <= n; ++y)
					mp[sum(x, j, i - 1, y)]++;
			}

			for(int x = i; x <= n; ++x) {
				for(int y = 1; y < j; ++y)
					ans += mp[sum(i, y, x, j - 1)];
			}
		}
	}
	printf("%d", ans);
	return 0;
}