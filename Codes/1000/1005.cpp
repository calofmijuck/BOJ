#include <bits/stdc++.h>
using namespace std;

int delay[1010], indeg[1010], dist[1010];

int main() {
    int t, n, k, x, y, w;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        vector<int> adj[1010];
        memset(indeg, 0, sizeof(indeg));
        memset(dist, -1, sizeof(dist));
        for(int i = 1; i <= n; ++i) {
            scanf("%d", delay + i);
        }
        for(int i = 0; i < k; ++i) {
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            indeg[y]++;
        }
        scanf("%d", &w);

        queue<int> q;
        for(int i = 1; i <= n; ++i) {
            if(!indeg[i]) {
                q.push(i);
                dist[i] = delay[i];
            }
        }
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == w) break;

            for(int next : adj[curr]) {
                if(!(--indeg[next])) q.push(next);
                dist[next] = max(dist[next], dist[curr] + delay[next]);
            }
        }
        printf("%d\n", dist[w]);
    }
    return 0;
}
