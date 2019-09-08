#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int d = 0;

int main() {
    int c, r, k, cnt = 1, x, y;
    cin >> c >> r >> k;
    if(k > c * r) {
        cout << 0;
        return 0;
    }
    int seat[r][c];
    memset(seat, 0, sizeof(seat));
    y = r - 1, x = 0;
    while(cnt < k) {
        int dx = x + dir[d][0];
        int dy = y + dir[d][1];
        if(dx < 0 || dx >= c || dy < 0 || dy >= r || seat[dy][dx] != 0) {
            d = (d + 1) % 4;
            continue;
        }
        seat[y][x] = cnt++;
        y = dy, x = dx;
    }
    cout << x + 1 << ' ' << r - y;
    return 0;
}