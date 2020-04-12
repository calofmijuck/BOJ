#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;
int ans[10];
bool used[10];

void dfs(int i, int cnt) {
	ans[cnt] = vec[i];
	used[i] = true;
	if(cnt == m - 1) {
		for(int j = 0; j < m; ++j) {
			cout << ans[j] << ' ';
		}
		cout << '\n';
		used[i] = false;
		return;
	}
	for(int idx = 0; idx < n; ++idx) {
		if(used[idx]) continue;
		dfs(idx, cnt + 1);
	}
	used[i] = false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vec.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	for(int i = 0; i < n; ++i)
		dfs(i, 0);
	return 0;
}
