#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll m = 14579;

int main() {
    ll a, b, ans = 1;
    cin >> a >> b;
    for(ll i = a; i <= b; ++i) {
        ans *= i * (i + 1) / 2 % m;
        ans %= m;
    }
    cout << ans;
    return 0;
}
