#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[20][20];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        dp[i][1] = 1;
        for(int j = 2; j <= m; ++j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    if(k != 0) {
        int x = (k + m - 1) / m, y = k % m;
        if(y == 0) y = m;
        cout << dp[x][y] * dp[n - x + 1][m - y + 1];
    } else cout << dp[n][m];
    return 0;
}