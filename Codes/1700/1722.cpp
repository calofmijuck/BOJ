#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool used[20];

int main() {
    ll n, m, k, arr[20], ans[20], cnt, fac[21] = {1}, res = 1;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i < n + 1; ++i) {
        fac[i] = i * fac[i - 1];
    }
    int j, tmp;
    if(m == 1) {
        scanf("%lld", &k);
        --k;
        for(int i = 1; i <= n; ++i) {
            cnt = k / fac[n - i] + 1;
            tmp = 0;
            for(j = 0; j < n; j++) {
                if(!used[j]) ++tmp;
                if(tmp == cnt) break;
            }
            used[j] = true;
            ans[i - 1] = j + 1;
            k = k % fac[n - i];
        }
        for(int i = 0; i < n; ++i)
            printf("%lld ", ans[i]);
    } else {
        for(int i = 0; i < n; ++i)
            scanf("%lld", &arr[i]);
        ll factor;
        for(int i = 0; i < n; ++i) {
            factor = 0;
            used[arr[i] - 1] = true;
            for(int j = 0; j < arr[i]; j++) {
                if(!used[j]) ++factor;
            }
            res += factor * fac[n - 1 - i];
        }
        printf("%lld", res);
    }
    return 0;
}
