#include <bits/stdc++.h>
using namespace std;

int main() {
	int x[5], y[5];
	for(int i = 1; i <= 4; ++i) cin >> x[i] >> y[i];
	int w = max(min(x[2], x[4]) - max(x[1], x[3]), 0);
	int h = max(min(y[1], y[3]) - max(y[2], y[4]), 0);
	cout << (long long) w * h;
	return 0;
}