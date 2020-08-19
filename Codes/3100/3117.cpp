#include <bits/stdc++.h>
using namespace std;

int dp[30][100001];

int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector<int> start;
    for(int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        start.push_back(x);
    }
    for(int i = 0; i < k; ++i) {
        int x; scanf("%d", &x);
        dp[0][i + 1] = x;
    }
    for(int j = 1; j < 30; ++j) {
        for(int i = 1; i <= k; ++i)
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
    }
    for(int v : start) {
        int exp = m - 1, cnt = 0;
        while(exp > 0) {
            if(exp & 1)
                v = dp[cnt][v];
            exp >>= 1;
            cnt++;
        }
        printf("%d ", v);
    }
    return 0;
}