#include <bits/stdc++.h>
using namespace std;

// dp[i][j][k] : left i, right j, k steps
int dp[5][5][101010];
int step[101010], i;

int solve(int l, int r, int k) {
    if(k == i - 1) return 0;
    int& ret = dp[l][r][k];
    if(ret != -1) return ret;

    if(l == step[k] || r == step[k]) return 1 + solve(l, r, k + 1);

    int x1 = (step[k] - l) % 2 ? 3 : 4, x2 = (step[k] - r) % 2 ? 3 : 4;
    if(l == 0) x1 = 2;
    if(r == 0) x2 = 2;
    x1 += solve(step[k], r, k + 1);
    x2 += solve(l, step[k], k + 1);

    return ret = min(x1, x2);
}

int main() {
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", step + i) && step[i++]);

    printf("%d", solve(0, 0, 0));
    return 0;
}
