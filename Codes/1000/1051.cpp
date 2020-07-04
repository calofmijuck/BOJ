#include <bits/stdc++.h>
using namespace std;

string str[51];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> str[i];
    int ans = 0, l = min(m, n);
    for(int k = 1; k <= l; ++k) {
        for(int i = 0; i < n - k; ++i) {
            for(int j = 0; j < m - k; ++j) {
                if(str[i][j] == str[i][j + k] && str[i][j + k] == str[i + k][j + k] && str[i + k][j] == str[i][j]) {
                    ans = max(ans, k);
                }
            }
        }
    }
    ans++;
    cout << ans * ans;
    return 0;
}