#include <bits/stdc++.h>
using namespace std;

int arr[220], dp[220][220];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, y;
    cin >> n >> y;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        for(int j = i - 1; j >= 0; --j) {
            dp[j][i] = 0x3f3f3f3f;
            for(int k = j; k < i; ++k) {
                dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + (arr[j] != arr[k + 1]));
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
