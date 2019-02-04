#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
#define INF 0x6fffffff

int dp[105][10101];

int main() {
    int t, n, m, k, u, v, c, d;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; ++j) dp[i][j] = INF;
        }
        dp[1][0] = 0;
        vector<tiii> adj[105];
        for(int i = 0; i < k; ++i) {
            scanf("%d %d %d %d", &u, &v, &c, &d);
            adj[u].push_back({v, c, d});
        }
        priority_queue<tiii> pq;
        pq.push({0, 1, 0});
        bool exist = false;
        while(!pq.empty()) {
            tiii curr = pq.top(); pq.pop();
            int ctime = -get<0>(curr), ccity = get<1>(curr), ccost = get<2>(curr);
            if(ccity == n) {
                printf("%d\n", ctime);
                exist = true;
                break;
            }
            if(dp[ccity][ccost] < ctime) continue;
            for(tiii next : adj[ccity]) {
                int ncity = get<0>(next), ncost = get<1>(next), ntime = get<2>(next);
                if(ccost + ncost > m) continue;
                if(dp[ncity][ccost + ncost] > ctime + ntime) {
                    dp[ncity][ccost + ncost] = ctime + ntime;
                    pq.push({-ntime-ctime, ncity, ccost + ncost});
                }
            }
        }
        if(!exist) printf("Poor KCM\n");
    }
    return 0;
}
