#include <bits/stdc++.h>
using namespace std;

int A[101][101], B[101][101], ans[101][101];

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) scanf("%d", &A[i][j]);
    }
    scanf("%d %d", &m, &k);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) scanf("%d", &B[i][j]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            ans[i][j] = 0;
            for(int x = 0; x < m; x++) ans[i][j] += A[i][x] * B[x][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) printf("%d ", ans[i][j]);
        puts("");
    }
    return 0;
}
