#include <bits/stdc++.h>
using namespace std;

int mp[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, l;
	cin >> n >> l;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			cin >> mp[i][j];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int cnt = 1;
		for(int j = 1; j < n; ++j) {
			int d = mp[i][j] - mp[i][j - 1];
			if(d == 0) cnt++;
			else if(d == 1 && cnt >= l) cnt = 1;
			else if(d == -1 && cnt >= 0) cnt = 1 - l;
			else {
				cnt = -1;
				break;
			}
		}
		ans += (cnt >= 0);
	}
	for(int j = 0; j < n; ++j) {
		int cnt = 1;
		for(int i = 1; i < n; ++i) {
			int d = mp[i][j] - mp[i - 1][j];
			if(d == 0) cnt++;
			else if(d == 1 && cnt >= l) cnt = 1;
			else if(d == -1 && cnt >= 0) cnt = 1 - l;
			else {
				cnt = -1;
				break;
			}
		}
		ans += (cnt >= 0);
	}
	cout << ans;
	return 0;
}