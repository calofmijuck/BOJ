#include <bits/stdc++.h>
using namespace std;

const int MOD = 9901;
int dp[3][101010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    dp[0][1] = dp[1][1] = dp[2][1] = 1;
    for(int i = 2; i <= n; ++i) {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
        dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
    }
    cout << (dp[0][n] + dp[1][n] + dp[2][n]) % MOD;
    return 0;
}