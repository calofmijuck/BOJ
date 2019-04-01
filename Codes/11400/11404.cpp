#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 0x7FFFFFFF

ll dist[150][150];

int main() {
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j) dist[i][i] = 0;
            else dist[i][j] = MAX;
        }
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = min(dist[u][v], (ll) w);
    }
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) printf("%lld ", dist[i][j] != MAX ? dist[i][j] : 0);
        puts("");
    }
    return 0;
}
