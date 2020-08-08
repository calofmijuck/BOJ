#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2000001

typedef long long ll;

int cnt[MAX_N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	ll ans = 0;
	for(ll i = 1; i < MAX_N; ++i) {
		ll div = 0;
		for(ll j = i; j < MAX_N; j += i)
			div += cnt[j];
		if(div >= 2)
			ans = max(ans, i * div);
	}
	printf("%lld", ans);
	return 0;
}