#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii tree[10101], widthrange[10101];
int level[10101], width[10101];
bool hasparent[10101];

int dfs(int v, int lev, int offset) {
    if(v == -1) return 0;
    level[v] = lev;
    int left = dfs(tree[v].first, lev + 1, offset);
    width[v] = offset + left + 1;
    int right = dfs(tree[v].second, lev + 1, width[v]);
    if(widthrange[lev].first == 0) widthrange[lev].first = width[v];
    if(width[v] > widthrange[lev].second) widthrange[lev].second = width[v];
    return left + right + 1;
}

int findroot() {
    for(int i = 1; i <= 10101; ++i) if(!hasparent[i]) return i;
}

int main() {
    int n, v, lc, rc;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v);
        scanf("%d %d", &lc, &rc);
        tree[v].first = lc;
        tree[v].second = rc;
        hasparent[lc] = hasparent[rc] = true;
    }
    int root = findroot();
    dfs(root, 1, 0);
    int maxr = 0, lev = 0;
    for(int i = 1; i <= n; ++i) {
        int r = widthrange[i].second - widthrange[i].first + 1;
        if(r > maxr) {
            maxr = r;
            lev = i;
        }
    }
    printf("%d %d", lev, maxr);
    return 0;
}
