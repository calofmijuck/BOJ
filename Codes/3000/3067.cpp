// also same as 9084
#include <bits/stdc++.h>
using namespace std;

int coins[20];
int dp[10001];

int solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int target;
    cin >> target;

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= target; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[target];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
