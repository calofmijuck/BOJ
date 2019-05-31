#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, string> mp;
    int n, m;
    cin >> m >> n;
    string site, pass;
    for(int i = 0; i < m; ++i) {
        cin >> site >> pass;
        mp.insert({site, pass});
    }
    for(int i = 0; i < n; ++i) {
        cin >> site;
        cout << mp[site] << '\n';
    }
    return 0;
}
