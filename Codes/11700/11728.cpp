#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(m);
    for(int i = 0; i < n; ++i) cin >> v[i];
    for(int i = 0; i < m; ++i) cin >> w[i];
    
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(v[i] < w[j]) cout << v[i++] << ' ';
        else cout << w[j++] << ' ';
    }
    while(i < n) cout << v[i++] << ' ';
    while(j < m) cout << w[j++] << ' ';
    return 0;
}
