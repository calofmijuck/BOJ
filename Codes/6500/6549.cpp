#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[101010];

ll solve(ll left, ll right) {
    if(left == right) return arr[left];
    ll mid = (left + right) / 2;
    ll ret = max(solve(left, mid), solve(mid + 1, right));
    ll low = mid, high = mid + 1;
    ll height = min(arr[low], arr[high]);
    ret = max(ret, height * 2);
    while(left < low || high < right) {
        if(high < right && (low == left || arr[low - 1] < arr[high + 1])) {
            high++;
            height = min(height, arr[high]);
        } else {
            low--;
            height = min(height, arr[low]);
        }
        ret = max(ret, height * (high - low + 1));
    }
    return ret;
}

int main() {
    ll n;
    while(scanf("%lld", &n) && n) {
        for(int i = 0; i < n; ++i) scanf("%lld", arr + i);
        printf("%lld\n", solve(0, n - 1));
    }
    return 0;
}
