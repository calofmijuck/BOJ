#include <bits/stdc++.h>
using namespace std;

int n, m, ans[10];
vector<int> vec;

void solve(int v, int idx) {
    ans[idx] = vec[v];
    if(idx == m - 1) {
        for(int i = 0; i < m; ++i) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = v; i < n; ++i)
        solve(i, idx + 1);
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