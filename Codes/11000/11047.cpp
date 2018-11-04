#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);
    int coin[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", coin + i);
    }
    while(n--) {
        ans += k / coin[n];
        k %= coin[n];
    }
    printf("%d", ans);
    return 0;
}
