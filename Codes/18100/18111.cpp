#include <bits/stdc++.h>
using namespace std;

int m, n, b;
int gnd[550][550];

int solve(int h, int block) {
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(gnd[i][j] > h) {
                int d = gnd[i][j] - h;
                ret += 2 * d;
                block += d;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(gnd[i][j] < h) {
                int d = h - gnd[i][j];
                ret += d;
                block -= d;
                if(block < 0) return 0x7fffffff;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n >> b;
    int mi = 300, mx = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> gnd[i][j];
            mi = min(mi, gnd[i][j]);
            mx = max(mx, gnd[i][j]);
        }
    }
    int t = 0x3fffffff, h;
    for(int k = mi; k <= mx; ++k) {
        int c = solve(k, b);
        if(t >= c) {
            t = c;
            h = k;
        }
    }
    cout << t << ' ' << h;
    return 0;
}
