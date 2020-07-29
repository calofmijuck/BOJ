#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> adj[300030];

int main() {
    int n, u, v;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll dCnt = 0, gCnt = 0;
    for(int i = 1; i <= n; ++i) {
        ll tmp = 0;
        for(int j : adj[i])
            tmp += ((int) adj[i].size() - 1) * ((int) adj[j].size() - 1);
        dCnt += tmp;
        if(adj[i].size() >= 3) {
            ll deg = adj[i].size();
            gCnt += deg * (deg - 1) / 2 * (deg - 2) / 3;
        }
    }
    dCnt /= 2;
    if(dCnt > 3 * gCnt) puts("D");
    else if(dCnt < 3 * gCnt) puts("G");
    else puts("DUDUDUNGA");
    return 0;
}