#include <bits/stdc++.h>
using namespace std;

int dp[50505];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i) {
        dp[i] = 0x3fffffff;
        for(int j = 1; j * j <= i; ++j) 
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
    cout << dp[n];
    return 0;
}
