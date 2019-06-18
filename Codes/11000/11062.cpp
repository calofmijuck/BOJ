#include <bits/stdc++.h>
using namespace std;

int card[1010], dp[1010][1010], sum[1010][1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> card[i];
        for(int i = 0; i < n; ++i) {
            sum[i][i] = card[i];
            dp[i][i] = 0;
            for(int j = i + 1; j < n; ++j) {
                dp[i][j] = 0;
                sum[i][j] = sum[i][j - 1] + card[j];
            }
        }
        for(int i = 0; i < n; ++i) dp[i][i] = card[i];
        for(int k = 1; k < n; ++k) {
            for(int i = 0; i < n - k; ++i) {
                dp[i][i + k] = max(card[i] + sum[i + 1][i + k] - dp[i + 1][i + k], card[i + k] + sum[i][i + k - 1] - dp[i][i + k - 1]);
            }
        }
        cout << dp[0][n - 1];
    }
    return 0;
}
