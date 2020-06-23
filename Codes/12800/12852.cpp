#include <bits/stdc++.h>
using namespace std;

int dp[3101010], ans[3101010];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	memset(dp, 0x3f, sizeof(dp));
	dp[1] = 0;
	for(int i = 1; i <= n; ++i) {
		if(dp[3 * i] > dp[i] + 1) {
			dp[3 * i] = dp[i] + 1;
			ans[3 * i] = i;
		}
		if(dp[2 * i] > dp[i] + 1) {
			dp[2 * i] = dp[i] + 1;
			ans[2 * i] = i;
		}
		if(dp[i + 1] > dp[i] + 1) {
			dp[i + 1] = dp[i] + 1;
			ans[i + 1] = i;
		}
	}
	cout << dp[n] << '\n';
	int curr = n;
	cout << curr << ' ';
	while(ans[curr] != 0) {
		curr = ans[curr];
		cout << curr << ' ';
	}
	return 0;
}