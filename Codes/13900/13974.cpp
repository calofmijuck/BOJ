#include <bits/stdc++.h>
using namespace std;

#define N 5050
#define MAX 0x7fffffff

int page[N], idx[N][N], dp[N][N], sum[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> page[i];
			sum[i] = sum[i - 1] + page[i];
			dp[i - 1][i] = 0;
			idx[i - 1][i] = i;
		}
		for(int d = 2; d <= n; ++d) {
			for(int i = 0; i + d <= n; ++i) {
				int j = i + d;
				dp[i][j] = MAX;
				for(int k = idx[i][j - 1]; k <= idx[i + 1][j]; ++k) {
					int curr = dp[i][k] + dp[k][j] + sum[j] - sum[i];
					if(dp[i][j] > curr) {
						dp[i][j] = curr;
						idx[i][j] = k;
					}
				}
			}
		}
		cout << dp[0][n] << '\n';
	}
}
