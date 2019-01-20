#include <bits/stdc++.h>
using namespace std;

char ans[51] = {'1'};

void solve(int st, int ed, int mid, int n) {
    if(n == 1) {
        printf("%d %d\n", st, ed);
        return;
    }
    solve(st, mid, ed, n - 1);
    printf("%d %d\n", st, ed);
    solve(mid, ed, st, n - 1);
}

int main() {
    int n, tmp, cnt = 0;
    char ctmp;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        tmp = 0;
        for(int j = cnt; j >= 0; --j) {
            tmp += (ans[j] - '0') * 2;
            ans[j] = tmp % 10 + '0';
            tmp /= 10;
        }
        if(tmp > 0) {
            ctmp = tmp + '0';
            ++cnt;
            for(int j = cnt; j >= 1; --j) ans[j] = ans[j - 1];
            ans[0] = ctmp;
        }
    }
    ans[cnt]--;
    printf("%s\n", ans);
    if(n <= 20) solve(1, 3, 2, n);
    return 0;
}
