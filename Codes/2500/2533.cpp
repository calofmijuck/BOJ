#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000001

vector<int> graph[MAX_N], tree[MAX_N];

int dp[MAX_N][2];
bool visited[MAX_N];

int find_min_adapters(int current, bool is_early_adapter) {
    if (dp[current][is_early_adapter] != -1) {
        return dp[current][is_early_adapter];
    }

    dp[current][is_early_adapter] = is_early_adapter ? 1 : 0;

    for (int child : tree[current]) {
        if (is_early_adapter) {
            dp[current][is_early_adapter] += min(find_min_adapters(child, true), find_min_adapters(child, false));
        } else {
            dp[current][is_early_adapter] += find_min_adapters(child, true);
        }
    }

    return dp[current][is_early_adapter];
}

void dfs(int v) {
    visited[v] = true;
    for (int next : graph[v]) {
        if (visited[next]) {
            continue;
        }

        tree[v].push_back(next);
        dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    memset(dp, -1, sizeof(dp));
    cout << min(find_min_adapters(1, true), find_min_adapters(1, false));
    return 0;
}
