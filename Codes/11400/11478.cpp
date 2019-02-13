#include <bits/stdc++.h>
using namespace std;

struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t): group(_group), t(_t) {}
	bool operator()(int a, int b) {
		if(group[a] != group[b]) return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

vector<int> SuffixArray(const string& s) {
	int n = s.size();
	int t = 1;
	vector<int> group(n + 1);
	for(int i = 0; i < n; ++i) group[i] = s[i];
	group[n] = -1;
	vector<int> perm(n);
	for(int i = 0; i < n; ++i) perm[i] = i;
	while(t < n) {
		Comparator cmp(group, t);
		sort(perm.begin(), perm.end(), cmp);
		t *= 2;
		if(t >= n) break;
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for(int i = 1; i < n; ++i) {
			if(cmp(perm[i - 1], perm[i])) newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else newGroup[perm[i]] = newGroup[perm[i - 1]];
		}
		group = newGroup;
	}
	return perm;
}

int commonPrefix(const string& s, int i, int j) {
	int k = 0;
	while(i < s.size() && j < s.size() && s[i] == s[j]) {
		++i; ++j; ++k;
	}
	return k;
}

int cntSubstr(const string &s) {
	vector<int> a = SuffixArray(s);
	int ret = 0, n = s.size();
	for(int i = 0; i < a.size(); ++i) {
		int cp = 0;
		if(i > 0) cp = commonPrefix(s, a[i - 1], a[i]);
		ret += n - a[i] - cp;
	}
	return ret;
}

int main() {
	string str;
	cin >> str;
	int ans = cntSubstr(str);
	printf("%d", ans);
	return 0;
}
