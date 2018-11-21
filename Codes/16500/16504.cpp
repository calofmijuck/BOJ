#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll paper[1050][1050];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%lld", &paper[i][j]);
        }
    }
    while(n != 1) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n / 2; ++j) {
                paper[i][j] += paper[i][n + 1 - j];
            }
        }
        for(int i = 1; i <= n / 2; ++i) {
            for(int j = 1; j <= n / 2; ++j) {
                paper[i][j] += paper[n + 1 - i][j];
            }
        }
        n >>= 1;
    }
    printf("%lld", paper[1][1]);
    return 0;
}
