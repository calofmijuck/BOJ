#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[1010101], n, m;

ll process(ll h) {
    ll ret = 0;
    for(int i = 0; i < n; ++i) ret += max(arr[i] - h, 0LL);
    return ret;
}

int main() {
    ll mx = 0;
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", arr + i);
        mx = max(mx, arr[i]);
    }
    ll left = 0, right = mx, mid, res;
    while(left <= right) {
        mid = (left + right) >> 1;
        ll sum = process(mid);
        if(sum < m) right = mid - 1;
        else {
            res = mid;
            left = mid + 1;
        }
    }
    printf("%lld", res);
    return 0;
}
