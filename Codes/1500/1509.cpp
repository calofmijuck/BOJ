#include <bits/stdc++.h>
using namespace std;

bool isPal[2505][2505];
int dp[2505];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    memset(dp, 0x3f, sizeof(dp));
    memset(isPal, true, sizeof(isPal));
    int n = str.size();
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= n - i; ++j)
            isPal[j][j + i] = isPal[j + 1][j + i - 1] && (str[j - 1] == str[j + i - 1]); 
    }
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; ++i) {
        dp[i] = i;
        for(int j = i; j >= 1; --j) {
            if(isPal[j][i])
                dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[n];
    return 0;
}
