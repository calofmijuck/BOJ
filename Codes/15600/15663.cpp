#include <bits/stdc++.h>
using namespace std;

int n, m, seq[10];
bool used[10];
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
    used[v] = true;
    if(idx == m - 1) {
        string s = build();
        if(ans.count(s) == 0) {
            ans.insert(s);
            cout << s << '\n';
        }
        used[v] = false;
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(!used[i]) solve(i, idx + 1);
    }
    used[v] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vec.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; ++i)
        solve(i, 0);
    return 0;
}