#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans, res;
bool check[10];

int solve(int i) {
    int cnt = 0;
    while(i) {
        if(check[i % 10]) return -1;
        i /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &k);
        check[k] = true;
    }
    ans = n - 100;
    if(ans < 0) ans *= -1;
    if(!check[0]) ans = min(ans, n + 1);
    for(int i = n; i < 1111111; ++i) {
        res = solve(i);
        if(res > 0) {
            res += i - n;
            ans = min(ans, res);
            break;
        }
    }
    for(int i = n; i > 0; --i) {
        res = solve(i);
        if(res > 0) {
            res += n - i;
            ans = min(ans, res);
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
