#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll arr[20];

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(a % b, b);
}

pll addinv(ll x, pll curr) {
    ll tmp = arr[x] * curr.second;
    curr.first += tmp;
    ll g = gcd(curr.first, curr.second);
    curr.second /= g;
    curr.first /= g;
    return {curr.second, curr.first};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    pll ans = {1, arr[n - 1]};
    for(int i = n - 2; i >= 0; --i) {
        cout << ans.first << ' ' << ans.second;
        ans = addinv(arr[i], ans);
    }
    ans.first = ans.second - ans.first;
    cout << ans.first << ' ' << ans.second;
    return 0;
}