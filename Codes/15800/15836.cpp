#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, p, q, cnt = 1;
    while(scanf("%d %d %d %d", &m, &n, &p, &q) && (m || n || p || q)) {
        int A[m][n], B[p][q], C[m][q];
        memset(C, 0, sizeof(C));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        for(int i = 0; i < p; i++) {
            for(int j = 0; j < q; j++) {
                scanf("%d", &B[i][j]);
            }
        }
        if(n != p) {
            printf("Case #%d:\nundefined\n", cnt);
            cnt++;
            continue;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < q; j++) {
                for(int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        printf("Case #%d:\n", cnt);
        for(int i = 0; i < m; i++) {
            printf("| ");
            for(int j = 0; j < q; j++) {
                printf("%d ", C[i][j]);
            }
            puts("|");
        }
        ++cnt;
    }
}
