#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll query(ll x) {
	ll ret = 0;
	ll mask = 1LL << 62;
	for(int i = 62; i >= 0; --i, mask >>= 1) {
		if((x & mask) == 0) continue;
		ret += 1 + i * (1LL << (i - 1));
		x -= mask;
		ret += x;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll a, b;
	cin >> a >> b;
	cout << query(b) - query(a - 1);
	return 0;
}
