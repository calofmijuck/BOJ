#include <bits/stdc++.h>
using namespace std;

char img[13][25], img2[13][25];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%s", img[i]);
    for(int i = 0; i < n; ++i) scanf("%s", img2[i]);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 2 * m; j += 2) {
            if(img2[i][j] != img2[i][j + 1] || img2[i][j] != img[i][j / 2]) {
                printf("Not Eyfa");
                return 0;
            }
        }
    }
    printf("Eyfa");
    return 0;
}
