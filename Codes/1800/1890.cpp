#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int board[110][110], n;
ll dp[110][110];

bool check(int x, int y) {
    if(x <= n && y <= n) return true;
    else return false;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) scanf("%d", &board[i][j]);
    }
    dp[1][1] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == n && j == n) break;
            int c = board[i][j];
            if(check(i + c, j)) dp[i + c][j] += dp[i][j];
            if(check(i, j + c)) dp[i][j + c] += dp[i][j];
        }
    }
    printf("%lld", dp[n][n]);
    return 0;
}
