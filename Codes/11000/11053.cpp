#include <bits/stdc++.h>
using namespace std;

int dp[1010], arr[1010];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for(int i = 0; i < n; ++i) {
		if(dp[i] == 0) dp[i] = 1;
		for(int j = 0; j < i; ++j) {
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = dp[0];
	for(int i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
