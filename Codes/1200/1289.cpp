#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MOD 1000000007

vector<pii> tree[101010];
bool visited[101010];
ll ans, dp[101010];

void solve(int v) {
    visited[v] = true;
    ll sum = 0, sqsum = 0, tmp;
    for(pii p : tree[v]) {
        if(visited[p.first]) continue;
        solve(p.first);
        tmp = p.second * (1 + dp[p.first]) % MOD;
        dp[v] = sum = (sum + tmp) % MOD;
        sqsum = (sqsum - (tmp * tmp) % MOD) % MOD;
        if(sqsum < 0) sqsum += MOD;
    }
    ans = (ans + sum + ((sum * sum) % MOD + sqsum) * 500000004 % MOD) % MOD;
}

int main() {
    int n, a, b, w;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &w);
        tree[a].push_back({b, w});
        tree[b].push_back({a, w});
    }
    solve(1);
    printf("%lld", ans);
    return 0;
}
