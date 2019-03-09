#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;
int dp[1010][10];

int main() {
    int n;
    scanf("%d", &n);
    for(int j = 0; j < 10; ++j) dp[0][j] = 1;
    for(int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0];
        for(int j = 1; j < 10; ++j) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    }
    int sum = 0;
    for(int j = 0; j < 10; ++j) sum = (sum + dp[n - 1][j]) % mod;
    printf("%d", sum);
    return 0;
}
