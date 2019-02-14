#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[5050], mi = numeric_limits<ll>::max();
int x, y, z;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%lld", arr + i);
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i) {
        int r =  n - 1, m = i, l = 0;
        while(l < m && m < r) {
            ll sum = arr[l] + arr[m] + arr[r];
            if(abs(sum) < mi) {
                mi = abs(sum);
                x = l, y = m, z = r;
            }
            if(sum < 0) ++l;
            else --r;
        }
    }
    printf("%lld %lld %lld", arr[x], arr[y], arr[z]);
    return 0;
}
