#include <bits/stdc++.h>
using namespace std;
int A[101][101], input, m, n;

int main() {
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &input);
            A[i][j] += input;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            printf("%d ", A[i][j]);
        }
        printf("%d\n", A[i][m - 1]);
    }
}
