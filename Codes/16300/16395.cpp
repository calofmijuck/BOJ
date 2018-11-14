#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long prod = 1;
	for(int i = 1; i <= k - 1; ++i)
		prod = prod * (n - i) / i;
	printf("%lld", prod);
	return 0;
}
