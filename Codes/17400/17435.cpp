#include <bits/stdc++.h>
using namespace std;

int f[20][200020];

void preprocess(int m) {
	for(int i = 1; i < 20; ++i) {
		for(int j = 1; j <= m; ++j) {
			f[i][j] = f[i - 1][f[i - 1][j]];
		}
	}
}

int query(int n, int x) {
	int i = 0;
	while(n > 0) {
		if(n & 1)
			x = f[i][x];
		n >>= 1;
		i++;
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m;
	cin >> m;
	for(int i = 1; i <= m; ++i)
		cin >> f[0][i];
	preprocess(m);
	int q;
	cin >> q;
	while(q--) {
		int n, x;
		cin >> n >> x;
		cout << query(n, x) << '\n';
	}
	return 0;
}