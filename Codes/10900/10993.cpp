#include <bits/stdc++.h>
using namespace std;

bool fig[1023][2045];

void solve(int d, int r, int c) {
    if(d == 1) {
        fig[r][c] = true;
        return;
    }
    int w = (2 << d) - 3, h = (1 << d) - 1;
    if(d % 2) {
        for(int i = 0; i < w; ++i) fig[r + h - 1][c + i] = true;
        for(int i = 0; i < h - 1; ++i) fig[r + i][c + w / 2 - i] = fig[r + i][c + w / 2 + i] = true;
        solve(d - 1, r + h / 2, c + (1 << (d - 1)));
    } else {
        for(int i = 0; i < w; ++i) fig[r][c + i] = true;
        for(int i = 0; i < h; ++i) fig[r + i][c + i] = fig[r + i][c + w - i - 1] = true;
        solve(d - 1, r + 1, c + (1 << (d - 1)));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n, 0, 0);
    int w = (2 << n) - 3, h = (1 << n) -1;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < (n % 2 ? w - h + i + 1 : w - i); ++j) printf("%c", fig[i][j] ? '*' : ' ');
        puts("");
    }
    return 0;
}
