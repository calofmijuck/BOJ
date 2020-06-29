#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> point;

ll solve(int k) {
	ll x = 0, y = 0;
	int idx = 0, mul;
	while(idx < point.size()) {
		if(k & 1) mul = 1;
		else mul = -1;
		x += mul * point[idx].first;
		y += mul * point[idx].second;
		idx++;
		k >>= 1;
	}
	return x * x + y * y;
}

int popCnt(int x) {
	int ret = 0;
	while(x > 0) {
		if(x & 1) ret++;
		x >>= 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t, n;
	cin >> t;
	while(t--) {
		ll x, y, mi = 0x7FFFFFFFFFFFFFFF;
		cin >> n;
		point.clear();
		for(int i = 0; i < n; ++i) {
			cin >> x >> y;
			point.emplace_back(x, y);
		}
		int lim = (1 << n) - 1;
		for(int k = (1 << (n / 2)) - 1; k <= lim; ++k) {
			if(popCnt(k) != n / 2) continue;
			mi = min(mi, solve(k));
		}
		cout << setprecision(15) << sqrt((long double) mi) << '\n';
	}
	return 0;
}