#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, t, c, p;
    cin >> n >> t >> c >> p;
    cout << (n - 1) / t * c * p;
    return 0;
}