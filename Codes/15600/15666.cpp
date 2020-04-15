#include <bits/stdc++.h>
using namespace std;

int n, m, seq[10];
vector<int> vec;
set<string> ans;

string build() {
    string ret = "";
    for(int i = 0; i < m; ++i) {
        ret += to_string(seq[i]);
        ret.push_back(' ');
    }    
    return ret;
}

void solve(int v, int idx) {
    seq[idx] = vec[v];
    if(idx == m - 1) {
        string s = build();
        if(ans.count(s) == 0) {
            ans.insert(s);
            cout << s << '\n';
        }
        return;
    }
    for(int i = v; i < vec.size(); ++i) {
        solve(i, idx + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int x;
    set<int> num;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        num.insert(x);
    }
    for(int i : num)
        vec.push_back(i);
    for(int i = 0; i < vec.size(); ++i)
        solve(i, 0);
    return 0;
}