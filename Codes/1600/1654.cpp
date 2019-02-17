#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[10101];

int main() {
    int n, k;
    scanf("%d %d", &k, &n);
    for(int i = 0; i < k; ++i) scanf("%d", arr + i);
    ll res = 0, st = 0, ed = 2147483647, mid = 0;
    while(st <= ed) {
        mid = (ed + st) / 2;
        ll cnt = 0;
        for(int i = 0; i < k; ++i) cnt += arr[i] / mid;
        if(cnt >= n) {
            res = max(res, mid);
            st = mid + 1;
        } else ed = mid - 1;
    }
    printf("%lld", res);
    return 0;
}
