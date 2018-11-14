#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll min(ll a, ll b) {
	return (a > b) ? b : a;
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n][3];
	ll ind[n][3] = {0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for(int i = 0; i < 3; i++) {
		ind[0][i] = arr[0][i];
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				if(j == k) continue;
				if(ind[i + 1][k] == 0) {
					ind[i + 1][k] = ind[i][j] + arr[i + 1][k];
				} else {
					ind[i + 1][k] = min(ind[i + 1][k], ind[i][j] + arr[i + 1][k]);
				}
			}
		}
	}
	ll ans = ind[n - 1][0];
	for(int i = 0; i < 3; i++) {
		ans = min(ans, ind[n - 1][i]);
	}
	printf("%lld", ans);
}
