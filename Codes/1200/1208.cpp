#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[41], n, s;
long long cnt;
ll lsum[2020202], rsum[2020202];

void subsum(ll x[], int n, int c) {
    for(int i = 0; i < (1 << n); ++i) {
        ll s = 0;
        for(int j = 0; j < n; ++j) {
            if(i & (1 << j)) s += arr[j + c];
        }
        x[i] = s;
    }
}

int main() {
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    subsum(lsum, n / 2, 0);
    subsum(rsum, n - n / 2, n / 2);
    int sizeX = 1 << (n / 2), sizeY = 1 << (n - n / 2);
    sort(rsum, rsum + sizeY);
    for(int i = 0; i < sizeX; ++i) {
        int target = s - lsum[i];
        auto high = upper_bound(rsum, rsum + sizeY, target);
        auto low = lower_bound(rsum, rsum + sizeY, target);
        cnt += high - low;
    }
    if(s == 0) {
        cnt -= 1;
    }
    printf("%lld", cnt);
    return 0;
}
