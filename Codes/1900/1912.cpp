#include <bits/stdc++.h>
using namespace std;

int arr[101010], dp[101010];

int main() {
    int n, ans = -2147483648;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", arr + i);
    dp[1] = arr[1];
    for(int i = 2; i <= n; ++i) dp[i] = max(arr[i], arr[i] + dp[i - 1]);
    for(int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    printf("%d", ans);
    return 0;
}
