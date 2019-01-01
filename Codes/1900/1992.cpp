#include <bits/stdc++.h>
using namespace std;

char data[70][70];

void solve(int a, int b, int n) {
    if(n == 1) {
        if(data[a][b] == '0') printf("0");
        else printf("1");
        return;
    }
    bool flag0 = true, flag1 = true;
    for(int i = a; i < a + n; ++i) {
        for(int j = b; j < b + n; ++j) {
            if(data[i][j] != '0') flag0 = false;
            if(data[i][j] != '1') flag1 = false;
        }
    }
    if(flag0) printf("0");
    else if(flag1) printf("1");
    else {
        int ns = n / 2;
        printf("(");
        solve(a, b, ns);
        solve(a, b + ns, ns);
        solve(a + ns, b, ns);
        solve(a + ns, b + ns, ns);
        printf(")");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%s", data[i]);
    solve(0, 0, n);
    return 0;
}
