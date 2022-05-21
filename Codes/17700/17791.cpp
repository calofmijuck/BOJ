#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool square_free(ll n) {
    for (ll i = 2; i * i < n; ++i) {
        if (n % (i * i) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for (int m = 2; m < n; ++m) {
        if (square_free((ll) m * n)) {
            cout << m;
            return 0;
        }
    }
    return 0;
}
