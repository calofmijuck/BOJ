#include <bits/stdc++.h>
using namespace std;

char ans[3072][6143];

void draw(int a, int b, int c, int d) {
    if((c - a) == 2 && (d - b) == 4) {
        ans[a][b + 2] = '*';
        ans[a + 1][b + 1] = '*';
        ans[a + 1][b + 3] = '*';
        for(int i = 0; i < 5; ++i) ans[c][b + i] = '*';
    } else {
        int tmp = (d - b) / 4 + 1;
        int mid = (a + c) / 2;
        int dim = (b + d) / 2;
        draw(a, b + tmp, mid, d - tmp);
        draw(mid + 1, b, c, dim - 1);
        draw(mid + 1, dim + 1, c, d);
    }
}

int main() {
    memset(ans, ' ', sizeof(ans));
    int n;
    scanf("%d", &n);
    int bot = 2 * n - 1;
    draw(0, 0, n - 1, bot - 1);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < bot; ++j) printf("%c", ans[i][j]);
        puts("");
    }
}
