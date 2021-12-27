#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000001

vector<int> tree[MAX_N];

int dp[MAX_N][2];

int find_min_adapters(int parent, int current, bool is_early_adapter) {
    if (dp[current][is_early_adapter] != -1) {
        return dp[current][is_early_adapter];
    }

    dp[current][is_early_adapter] = is_early_adapter ? 1 : 0;

    for (int child : tree[current]) {
        if (child == parent) {
            continue;
        }

        if (is_early_adapter) {
            dp[current][is_early_adapter] += min(find_min_adapters(current, child, true), find_min_adapters(current, child, false));
        } else {
            dp[current][is_early_adapter] += find_min_adapters(current, child, true);
        }
    }

    return dp[current][is_early_adapter];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));
    cout << min(find_min_adapters(0, 1, true), find_min_adapters(0, 1, false));
    return 0;
}
