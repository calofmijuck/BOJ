#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, ans = 1, in;
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &in);
        ans = (in % m * ans) % m;
    }
    printf("%lld", ans);
    return 0;
}
