#include <bits/stdc++.h>
using namespace std;

int mem[110], c[110], dp[110][10101], n, m;

int solve(int idx, int cost) {
	if(idx >= n) return 0;
	int &ret = dp[idx][cost];
	if(ret != -1) return ret;	
	ret = solve(idx + 1, cost);
	if(cost - c[idx] >= 0)
		ret = max(ret, mem[idx] + solve(idx + 1, cost - c[idx]));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> mem[i];
	for(int i = 0; i < n; ++i) cin >> c[i];
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for(; solve(0, ans) < m; ++ans);
	cout << ans;
	return 0;
}
