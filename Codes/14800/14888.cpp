#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647

int arr[12], mi = INF, mx = -INF, n, o[4];

void dfs(int curr, int idx, int p, int m, int t, int d) {
    if(idx == n) {
        mx = max(mx, curr);
        mi = min(mi, curr);
        return;
    }
    if(p > 0) dfs(curr + arr[idx], idx + 1, p - 1, m, t, d);
    if(m > 0) dfs(curr - arr[idx], idx + 1, p, m - 1, t, d);
    if(t > 0) dfs(curr * arr[idx], idx + 1, p, m, t - 1, d);
    if(d > 0) dfs(curr / arr[idx], idx + 1, p, m, t, d - 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    for(int i = 0; i < 4; ++i) scanf("%d", o + i);
    dfs(arr[0], 1, o[0], o[1], o[2], o[3]);
    printf("%d\n%d", mx, mi);
    return 0;
}
