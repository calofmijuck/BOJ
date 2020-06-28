#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

ll dp[8][101010];
pii edge[] = {{0, 1}, {0, 2}, {1, 3}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}, {4, 7}, {5, 6}, {6, 7}};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int d;
	cin >> d;
	dp[0][0] = 1;
	for(int t = 1; t <= d; ++t) {
		for(int i = 0; i < 12; ++i) {
			pii e = edge[i];
			int u = e.first, v = e.second;
			dp[u][t] = (dp[u][t] + dp[v][t - 1]) % MOD;
			dp[v][t] = (dp[v][t] + dp[u][t - 1]) % MOD;
		}
	}
	cout << dp[0][d];
	return 0;
}
