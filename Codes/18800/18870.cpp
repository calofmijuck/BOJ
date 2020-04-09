#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n;
	vector<pii> vec;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		vec.push_back({x, i});
	}
	sort(vec.begin(), vec.end());
	vector<int> ans(n);
	int curr = 0;
	ans[vec[0].second] = curr;
	for(int i = 1; i < n; ++i) {
		if(vec[i].first != vec[i - 1].first)
			curr++;
		ans[vec[i].second] = curr;
	}
	for(int e : ans)
		cout << e << ' ';
	return 0;
}
