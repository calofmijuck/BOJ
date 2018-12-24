#include <bits/stdc++.h>
using namespace std;

int st[301], dp[301];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", st + i);
    dp[1] = st[1];
    dp[2] = st[1] + st[2];
    for(int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 2], dp[i - 3] + st[i - 1]) + st[i];
    }
    printf("%d", dp[n]);
    return 0;
}
