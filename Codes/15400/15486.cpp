#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1500000;

int n;
int times[MAX_N], profit[MAX_N];
int dp[MAX_N + 1];

int solve() {
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1];
        if (times[i] + i - 1 < n) {
            dp[i] = max(dp[i], profit[i] + dp[i + times[i]]);
        }
    }
    return dp[0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> times[i] >> profit[i];
    }

    cout << solve();
    return 0;
}
