#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, cnt = 0;
	string str;
	cin >> n;
	unordered_map<string, int> mp;
	for(int i = 0; i < n; ++i) {
		cin >> str;
		mp[str] = i;
	}
	vector<string> out;
	for(int i = 0; i < n; ++i) {
		cin >> str;
		out.push_back(str);
	}
	for(int i = 0; i < n; ++i) {
		int rk = mp[out[i]];
		for(int j = i + 1; j < n; ++j) {
			if(rk > mp[out[j]]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}