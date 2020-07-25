#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll x, y, z;
	while(true) {
		cin >> x >> y >> z;
		if(x == 0 && y == 0 && z == 0) break;
		if((z - x) % y != 0) {
			cout << "X\n";
		} else {
			int k = (z - x) / y + 1;
			if(k <= 0) cout << "X\n";
			else cout << k << '\n';
		}
	}
	return 0;
}