#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, mi = 20000, sum = 0;
    scanf("%d %d", &m, &n);
    for(int i = 1; i * i <= n; ++i) {
        if(i * i >= m) {
            mi = min(mi, i * i);
            sum += i * i;
        }
    }
    if(mi == 20000) printf("-1");
    else printf("%d\n%d", sum, mi);
    return 0;
}
