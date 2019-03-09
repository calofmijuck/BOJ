#include <bits/stdc++.h>
using namespace std;

const int INF = 0x1FFFFFFF;

int n, dist[10][10], dp[10][1 << 10];

int tsp(int here, int visited) {
    if(visited == (1 << n) - 1) {
        if(!dist[here][0]) return INF;
        return dist[here][0];
    }
    int& ret = dp[here][visited];
    if(ret != 0) return ret;
    ret = INF;
    for(int next = 0; next < n; ++next) {
        if(visited & (1 << next)) continue;
        if(!dist[here][next]) continue;
        int cand = dist[here][next] + tsp(next, visited | (1 << next));
        ret = min(ret, cand);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) scanf("%d", &dist[i][j]);
    }
    printf("%d", tsp(0, 1));
    return 0;
}
