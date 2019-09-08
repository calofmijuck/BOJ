#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[105][23];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    dp[1][x] = 1;
    for(int i = 2; i < n; ++i) {
        cin >> x;
        for(int j = 0; j <= 20; ++j) {
            if(dp[i - 1][j] == 0) continue;
            int add = j + x;
            if(0 <= add && add <= 20) dp[i][add] += dp[i - 1][j];
            int sub = j - x;
            if(0 <= sub && sub <= 20) dp[i][sub] += dp[i - 1][j];
        }
    }
    cin >> x;
    cout << dp[n - 1][x] << '\n';
    return 0;
}