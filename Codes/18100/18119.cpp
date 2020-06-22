#include <bits/stdc++.h>
using namespace std;

int words[10010];

int preprocess(string str) {
	int ret = 0;
	for(char c : str)
		ret |= 1 << (c - 'a');
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		words[i] = preprocess(str);
	}
	int op, state = 0xFFFFFFFF;
	string str;
	for(int i = 0; i < m; ++i) {
		cin >> op >> str;
		int mask = 1 << (str[0] - 'a');
		state ^= mask;
		int cnt = 0;
		for(int j = 0; j < n; ++j) {
			if(words[j] == (words[j] & state))
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}