#include <cstdio>
using namespace std;
typedef long long ll;

ll MOD = 1000000009, dp[50505] = {1, 1, 1};

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 3; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 3]) % MOD;
    printf("%lld", dp[n]);
    return 0;
}
