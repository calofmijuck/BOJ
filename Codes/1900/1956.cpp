#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 0x3f3f3f3f

int gph[404][404];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int v, e, a, b, c;
    cin >> v >> e;
    memset(gph, INF, sizeof(gph));
    for(int i = 0; i < e; ++i) {
        cin >> a >> b >> c;
        gph[a][b] = c;
    }
    for(int k = 1; k <= v; ++k) {
        for(int i = 1; i <= v; ++i) {
            for(int j = 1; j <= v; ++j) {
                gph[i][j] = min(gph[i][j], gph[i][k] + gph[k][j]);
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= v; ++i) ans = min(ans, gph[i][i]);
    if(ans < INF) cout << ans;
    else cout << -1;
}