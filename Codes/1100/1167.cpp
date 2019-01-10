#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[101010];
bool visited[101010];
int ans;

int dfs(int v) {
    int max1 = 0, max2 = 0;
    for(pii i : adj[v]) {
        if(visited[i.first]) continue;
        visited[i.first] = true;
        int d = dfs(i.first) + i.second;
        if(d > max1) {
            max2 = max1;
            max1 = d;
        } else if(d > max2) max2 = d;
    }
    ans = max(ans, max1 + max2);
    return max1;
}

int main() {
    int v, src, dst, w;
    scanf("%d", &v);
    for(int i = 0; i < v; ++i) {
        scanf("%d", &src);
        while(scanf("%d", &dst) && dst + 1) {
            scanf("%d", &w);
            adj[src].push_back({dst, w});
        }
    }
    visited[1] = true;
    dfs(1);
    printf("%d", ans);
    return 0;
}
