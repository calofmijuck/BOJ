#include <bits/stdc++.h>
using namespace std;

string str[101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> str[i];
    cin >> k;
    if(k == 1) {
        for(int i = 0; i < n; ++i) cout << str[i] << '\n';
    } else if(k == 2) {
        for(int i = 0; i < n; ++i) {
            for(int j = str[i].size() - 1; j >= 0; --j) cout << str[i][j];
            cout << '\n';
        }
    } else {
        for(int i = n - 1; i >= 0; --i) cout << str[i] << '\n';
    }
}