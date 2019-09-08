#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    ll x = 1, y = 1, z = 2;
    for(int i = 1; i < n; ++i) {
        z = x + y;
        x = y, y = z;
    }
    cout << 2 * (x + y);
}