#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll weighted_triangular_number() {
    int n;
    cin >> n;

    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        result += (ll) i * (i + 1) * (i + 2) / 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cout << weighted_triangular_number() << '\n';
    }
    return 0;
}
