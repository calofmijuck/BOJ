#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, a0, a1, n, res;
    scanf("%d %d %02d %02d %d", &x, &y, &a0, &a1, &n);
    if(n == 0) {
        printf("%02d", a0);
    } else if(n == 1) {
        printf("%02d", a1);
    } else {
        for(int i = 2; i <= n; i++) {
            res = (x * a1 + y * a0) % 100;
            a0 = a1;
            a1 = res;
        }
        printf("%02d", res);
    }
}
