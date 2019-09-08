#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f

int dp[10101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k, x;
    cin >> n >> k;
    for(int i = 0; i <= k; ++i) dp[i] = INF;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        for(int j = x; j <= k; ++j) {
            if(j == x) dp[j] = 1;
            dp[j] = min(dp[j], dp[j - x] + 1);
        }
    }
    if(dp[k] == INF) cout << -1;
    else cout << dp[k];
}