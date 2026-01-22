#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[10101];
int ans;

int max_depth(int v) {
    int max1 = 0, max2 = 0;
    for (int i = 0; i < (int) adj[v].size(); ++i) {
        auto [next, weight] = adj[v][i];
        int curr = max_depth(next) + weight;
        if (curr > max1) {
            max2 = max1;
            max1 = curr;
        } else if (curr > max2) {
            max2 = curr;
        }
    }
    ans = max(ans, max1 + max2);
    return max1;
}

int main() {
    int n, p, c, w;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d %d", &p, &c, &w);
        adj[p].push_back({ c, w });
    }
    max_depth(1);
    printf("%d", ans);
}
