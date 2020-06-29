#include <bits/stdc++.h>
using namespace std;

bool prime[4000404];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	memset(prime, true, sizeof(prime));
	for(int p = 2; p * p <= n; ++p) {
		if(prime[p]) {
			for(int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	vector<int> primes;
	for(int i = 2; i <= n; ++i) {
		if(prime[i])
			primes.push_back(i);
	}
	int ans = 0;
	for(int i = 0; i < primes.size(); ++i) {
		int sum = 0, k = i;
		while(sum < n && k < primes.size()) {
			sum += primes[k++];
			if(sum == n) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}