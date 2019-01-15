#include <bits/stdc++.h>
using namespace std;
#define MAX 2147483647;

vector<int> graph[100010];
int dp[100010][20];

void dfs(int prev, int v) {
    dp[v][0] = MAX;
    for(int i = 1; i < 18; ++i) dp[v][i] += i;
    for(int next : graph[v]) {
        if(next == prev) continue;
        dfs(v, next);
        int f = 0, s = 0;
        for(int i = 1; i < 18; ++i) {
            if(dp[next][s] > dp[next][i]) s = i;
            if(dp[next][f] > dp[next][s]) swap(f, s);
        }
        for(int i = 1; i < 18; ++i) dp[v][i] += dp[next][i != f ? f : s];
    }
}

int main() {
    int n, u, v, ans = MAX;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, 1);
    for(int i = 1; i < 18; ++i) ans = min(ans, dp[1][i]);
    printf("%d", ans);
    return 0;
}
