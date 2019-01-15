#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[10101];
int ans;

int radius(int v) {
    int max1 = 0, max2 = 0;
    for(int i = 0; i < adj[v].size(); ++i) {
        pii p = adj[v][i];
        int curr = radius(p.first) + p.second;
        if(curr > max1) {
            max2 = max1;
            max1 = curr;
        } else if(curr > max2) max2 = curr;
    }
    ans = max(ans, max1 + max2);
    return max1;
}

int main() {
    int n, p, c, w;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; ++i) {
        scanf("%d %d %d", &p, &c, &w);
        adj[p].push_back({c, w});
    }
    radius(1);
    printf("%d", ans);
}
