#include <bits/stdc++.h>
using namespace std;

#define MAX 0x3f3f3f3f

int dp[5][5][101010];
int step[101010], i = 1;

int main() {
    memset(dp, 0x3f, sizeof(dp));
    while(scanf("%d", step + i) && step[i++]);

    dp[0][0][0] = 0;
    for(int k = 1; k < i; ++k) {
        for(int l = 0; l < 5; ++l) {
            for(int r = 0; r < 5; ++r) {
                if(dp[l][r][k - 1] == MAX) continue;

                int p = (step[k] == l) ? 1 : (step[k] - l) % 2 ? 3 : 4;
                if(l == 0) p = 2;
                dp[step[k]][r][k] = min(dp[step[k]][r][k], dp[l][r][k - 1] + p);

                int q = (step[k] == r) ? 1 : (step[k] - r) % 2 ? 3 : 4;
                if(r == 0) q = 2;
                dp[l][step[k]][k] = min(dp[l][step[k]][k], dp[l][r][k - 1] + q);
            }
        }
    }
    int ans = MAX;
    for(int l = 0; l < 5; ++l) {
        for(int r = 0; r < 5; ++r) {
            ans = min(ans, dp[l][r][i - 2]);
        }
    }
    printf("%d", ans);
    return 0;
}
