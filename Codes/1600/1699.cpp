#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f

int dp[101010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        dp[i] = INF;
        for(int j = 1; j * j <= i; ++j)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
    cout << dp[n];
}