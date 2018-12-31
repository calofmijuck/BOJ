#include <bits/stdc++.h>
using namespace std;

int paper[3000][3000], ans[3];

void solve(int a, int b, int n) {
    if(n == 1) {
        ans[paper[a][b] + 1]++;
        return;
    }
    bool flag[3] = {true, true, true};
    for(int i = a; i < a + n; ++i) {
        for(int j = b; j < b + n; ++j) {
            if(paper[i][j] != -1) flag[0] = false;
            if(paper[i][j] != 0) flag[1] = false;
            if(paper[i][j] != 1) flag[2] = false;
        }
    }
    if(flag[0]) ans[0]++;
    else if(flag[1]) ans[1]++;
    else if(flag[2]) ans[2]++;
    else {
        int ns = n / 3;
        solve(a, b, ns);
        solve(a, b + ns, ns);
        solve(a, b + 2 * ns, ns);
        solve(a + ns, b, ns);
        solve(a + ns, b + ns, ns);
        solve(a + ns, b + 2 * ns, ns);
        solve(a + 2 * ns, b, ns);
        solve(a + 2 * ns, b + ns, ns);
        solve(a + 2 * ns, b + 2 * ns, ns);
    }

}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) scanf("%d", &paper[i][j]);
    }
    solve(1, 1, n);
    printf("%d\n%d\n%d", ans[0], ans[1], ans[2]);
    return 0;
}
