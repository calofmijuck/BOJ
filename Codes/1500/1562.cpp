#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000000;
int dp[110][11][1050];

int mask(int k) {
    return 1 << k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= 9; ++i) dp[1][i][mask(i)] = 1;
    for(int k = 2; k <= n; ++k) {
        for(int i = 0; i <= 9; ++i) {
            for(int j = 1; j <= 1023; ++j) {
                if(i == 9) {
                    dp[k][i][j | mask(i)] = (dp[k][i][j | mask(i)] + dp[k - 1][i - 1][j]) % MOD;
                } else if(i != 0) {
                    dp[k][i][j | mask(i)] = (dp[k][i][j | mask(i)] + dp[k - 1][i - 1][j]) % MOD;
                }
            }
            for(int j = 1; j <= 1023; ++j) {
                if(i == 0) {
                    dp[k][i][j | mask(i)] = (dp[k][i][j | mask(i)] + dp[k - 1][i + 1][j]) % MOD;
                } else if(i != 9) {
                    dp[k][i][j | mask(i)] = (dp[k][i][j | mask(i)] + dp[k - 1][i + 1][j]) % MOD;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 9; ++i) ans = (ans + dp[n][i][1023]) % MOD;
    cout << ans;
    return 0;
}
