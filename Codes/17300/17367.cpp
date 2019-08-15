#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double dp[1100][7][7][7];
int MAX_N;

int prize(int a, int b, int c) {
    if(a == b && b == c) return 10000 + 1000 * a;
    if(a == b) return 1000 + 100 * a;
    if(b == c) return 1000 + 100 * b;
    if(a == c) return 1000 + 100 * c;
    return 100 * max({a, b, c});
}

double ex(int n, int a, int b, int c) {
    if(dp[n][a][b][c] != 0 ) return dp[n][a][b][c];
    if(n == MAX_N) return prize(a, b, c);
    int curr = prize(a, b, c);
    double sum = 0;
    for(int next = 1; next <= 6; ++next) {
        sum += ex(n + 1, b, c, next);
    }
    return dp[n][a][b][c] = max(sum / 6, (double) curr);
}

int main() {
    int n;
    scanf("%d", &n);
    MAX_N = n;
    double ans = 0;
    for(int a = 1; a <= 6; ++a) {
        for(int b = 1; b <= 6; ++b) {
            for(int c = 1; c <= 6; ++c) {
                double exp = ex(3, a, b, c);
                ans += exp;
            }
        }
    }
    printf("%.12lf", ans / 216);
    return 0;
}
