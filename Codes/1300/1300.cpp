#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int st = 1, ed = k, mid, ans;
    while(st <= ed) {
        long long cnt = 0;
        mid = (st + ed) / 2;
        for(int i = 1; i <= n; ++i) cnt += min(mid / i, n);
        if(cnt < k) st = mid + 1;
        else {
            ans = mid;
            ed = mid - 1;
        }
    }
    printf("%d", ans);
    return 0;
}
