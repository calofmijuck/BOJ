#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, y;
	cin >> x >> y;
	if(x > 0)
		cout << 1 + 3 * (y < 0);
	else
		cout << 2 + 1 * (y < 0);
	return 0;
}
