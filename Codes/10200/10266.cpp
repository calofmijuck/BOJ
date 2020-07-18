#include <bits/stdc++.h>
using namespace std;

#define MAX_N 360000

vector<int> preprocess(vector<bool> p){
    int m = p.size();
    vector<int> fail(m);
    fail[0] = 0;
    int j = 0;
    for(int i = 1; i < m; ++i){
        while(j > 0 && p[i] != p[j]) j = fail[j - 1];
        if(p[i] == p[j]) {
            fail[i] = j + 1;
            j++;
        } else fail[i] = 0;
    }
    return fail;
}

vector<int> kmp(vector<bool> s, vector<bool> p){
    auto fail = preprocess(p);
    vector<int> ans;
    int n = s.size(), m = p.size();
    int j = 0;
    for(int i = 0; i < n; ++i){
        while(j > 0 && s[i] != p[j]) j = fail[j - 1];
        if(s[i] == p[j]){
            if(j == m - 1){
                ans.push_back(i - m + 1);
                j = fail[j];
            } else j++;
        }
    }
    return ans;
}

vector<bool> a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x;
	cin >> n;
	a.resize(2 * MAX_N); b.resize(MAX_N);
	for(int i = 0; i < n; ++i) {
		cin >> x;
		a[x] = true;
	}
	for(int i = MAX_N; i < 2 * MAX_N; ++i)
		a[i] = a[i - MAX_N];
	for(int i = 0; i < n; ++i) {
		cin >> x;
		b[x] = true;
	}
	vector<int> ans = kmp(a, b);
	cout << ((ans.size() == 0) ? "impossible" : "possible");
	return 0;
}
