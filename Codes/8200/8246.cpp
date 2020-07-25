#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a, b, k;
    cin >> a >> b >> k;
    cout << (a / k) * (b / k) - max(0LL, a / k - 2) * max(0LL, b / k - 2);
    return 0;
}