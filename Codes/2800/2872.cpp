#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec(n);
	int mx = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &vec[i]);
		if(vec[i] == n)
			mx = i;
	}
	int ans = n - 1 - mx, cnt = 0;
	while(mx >= 0) {
		if(vec[mx] == n)
			n--;
		else
			cnt++;
		mx--;
	}
	printf("%d", ans + cnt);
	return 0;
}