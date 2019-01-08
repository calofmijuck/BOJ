#include <bits/stdc++.h>
using namespace std;

int arr[1010][1010], dp[1010][1010];

int main() {
    int n, m, mx = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%1d", &arr[i][j]);
        }
    }
    dp[1][1] = arr[1][1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(arr[i][j] == 1) dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
            else dp[i][j] = 0;
            mx = max(mx, dp[i][j]);
        }
    }
    printf("%d", mx * mx);
    return 0;
}
