#include <bits/stdc++.h>
using namespace std;

long long x[10010], y[10010];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lld %lld", x + i, y + i);
	x[n] = x[0], y[n] = y[0];
	double ans = 0.0;
	for(int i = 0; i < n; ++i) {
		ans += x[i] * y[i + 1];
		ans -= x[i + 1] * y[i];
	}
	printf("%.1lf", abs(ans) / 2);
	return 0;
}
