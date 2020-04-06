#include <bits/stdc++.h>
using namespace std;

#define MAX 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> dist;
    dist.resize(n);
    for(int i = 0; i < n; ++i) {
        dist[i].resize(n);
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            dist[i][j] = MAX;
        }
    }
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        dist[x - 1][y - 1] = 1;
        dist[y - 1][x - 1] = 1;
    }
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    int mi = MAX, arg = 0;
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = 0; j < n; ++j)
            sum += dist[i][j];
        if(sum < mi) {
            mi = sum;
            arg = i;
        }
    }
    cout << arg + 1;
    return 0;
}