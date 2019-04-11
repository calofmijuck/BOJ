#include <bits/stdc++.h>
using namespace std;

int arr[500][2], dp[505][505];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d %d", &arr[i][0], &arr[i][1]);
    for(int r = 1; r < n; ++r) {
        for(int i = 1; i <= n - r; ++i) {
            int j = i + r, m = 0x7FFFFFFF;
            for(int k = i; k < j; ++k) {
                m = min(m, dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1]);
            }
            dp[i][j] = m;
        }
    }
    printf("%d", dp[1][n]);
    return 0;
}
