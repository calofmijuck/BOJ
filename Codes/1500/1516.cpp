#include <bits/stdc++.h>
using namespace std;

int btime[501], ans[501], indeg[501];
vector<int> adj[501];
queue<int> q;

int main() {
    int n, x, c;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &btime[i]);
        while(scanf("%d", &x) && x + 1) {
            adj[x].push_back(i);
            indeg[i]++;
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(indeg[i] == 0) q.push(i);
        ans[i] += btime[i];
    }
    while(!q.empty()) {
        c = q.front(); q.pop();
        for(auto v : adj[c]) {
            ans[v] = max(ans[v], ans[c] + btime[v]);
            if(--indeg[v] == 0) q.push(v);
        }
    }
    for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    return 0;
}
