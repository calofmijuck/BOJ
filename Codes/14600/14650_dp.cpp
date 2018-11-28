#include <bits/stdc++.h>
using namespace std;

int dp[10] = {0, 0, 2};

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 3; i < 10; ++i) dp[i] = 3 * dp[i - 1];
    printf("%d", dp[n]);
    return 0;
}
