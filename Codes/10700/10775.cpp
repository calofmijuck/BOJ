#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& p, int x) {
	if(p[x] < 0)
		return x;
	return p[x] = find(p, p[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> p(n + 1, -1);
	for(int i = 0; i < m; ++i) {
		int x, t;
		cin >> x;
		if((t = find(p, x)) == 0) break;
		p[t] = t - 1;
		ans++;
	}
	cout << ans;
	return 0;
}