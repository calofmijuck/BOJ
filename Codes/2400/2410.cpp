#include <cstdio>
using namespace std;

int dp[1010101] = {1, 1};

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i) {
        if(i & 1) dp[i] = dp[i - 1];
        else dp[i] = (dp[i - 1] + dp[i / 2]) % 1000000000;
    }
    printf("%d", dp[n]);
    return 0;
}
