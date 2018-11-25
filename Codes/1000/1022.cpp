#include <bits/stdc++.h>
using namespace std;

int ans[50][50];

int main() {
    int r1, c1, r2, c2, x, y;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            x = i - r1, y = j - c1;
            if(i - j < 0) {
                if(i + j < 0) ans[x][y] = 4 * i * i + i - j + 1;
                else ans[x][y] = 4 * j * j - 3 * j - i + 1;
            } else {
                if(i + j < 0) ans[x][y] = 4 * j * j - j + i + 1;
                else ans[x][y] = 4 * i * i + 3 * i + j + 1;
            }
        }
    }
    int mx = max(max(max(ans[0][0], ans[0][c2 - c1]), ans[r2 - r1][0]), ans[r2- r1][c2 - c2]);
    int dig = log10(mx) + 1;
    for(int i = 0; i <= r2 - r1; i++) {
        for(int j = 0; j <= c2 - c1; j++) {
            printf("%*d ", dig, ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
