#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int mp[1010][1010], l[1010][1010], u[1010][1010], r[1010][1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cin >> mp[i][j];
    }
    for(int j = 0; j < m; ++j) u[0][j] = -INF;
    for(int j = 0; j < m; ++j) r[0][j] = -INF;
    u[0][0] = l[0][0] = mp[0][0];
    for(int j = 1; j < m; ++j) l[0][j] = l[0][j - 1] + mp[0][j];

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < m; ++j) u[i][j] = max({u[i - 1][j], l[i - 1][j], r[i - 1][j]}) + mp[i][j];
        l[i][0] = -INF;
        for(int j = 1; j < m; ++j) l[i][j] = max(u[i][j - 1], l[i][j - 1]) + mp[i][j];
        r[i][m - 1] = -INF;
        for(int j = m - 2; j >= 0; --j) r[i][j] = max(u[i][j + 1], r[i][j + 1]) + mp[i][j];
    }

    cout << max(l[n - 1][m - 1], u[n - 1][m - 1]);
}