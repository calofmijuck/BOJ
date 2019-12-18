#include <bits/stdc++.h>
using namespace std;

#define MAX 0x3f3f3f3f

int arr[1010][3], dp[1010][3];

void run(int n) {
    for(int i = 2; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, ans = MAX;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    dp[1][0] = arr[1][0]; dp[1][1] = dp[1][2] = MAX;
    run(n);
    ans = min({ans, dp[n][1], dp[n][2]});
    dp[1][1] = arr[1][1]; dp[1][0] = dp[1][2] = MAX;
    run(n);
    ans = min({ans, dp[n][0], dp[n][2]});
    dp[1][2] = arr[1][2]; dp[1][0] = dp[1][1] = MAX;
    run(n);
    ans = min({ans, dp[n][0], dp[n][1]});    
    cout << ans;
    return 0;
}
