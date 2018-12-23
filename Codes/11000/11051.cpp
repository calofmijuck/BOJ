#include <bits/stdc++.h>
using namespace std;

int C[1010][1010];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        C[i][1] = i;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 10007;
        }
    }
    printf("%d", C[n][k]);
    return 0;
}
