#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a, b;
    cin >> a >> b;
    if(a < 3) a = 4;
    a = (a + 1) / 2;
    b /= 2;
    ll ans = (a + b) * (b - a + 1);
    cout << (ans > 0 ? ans : 0);
    return 0;
}
