#include <bits/stdc++.h>
using namespace std;

int ans[1010101] = {1};

int main() {
    int t, n, m;
    scanf("%d", &t);
    int cnt = 1;
    for(int i = 1; i <= 1000000; ++i) {
        int tmp = i;
        while(tmp > 0) {
            if(tmp % 10 == 0) cnt++;
            tmp /= 10;
        }
        ans[i] = cnt;
    }
    while(t--) {
        scanf("%d %d", &n, &m);
        if(n == 0) printf("%d\n", ans[m]);
        else printf("%d\n", ans[m] - ans[n - 1]);
    }
    return 0;
}
