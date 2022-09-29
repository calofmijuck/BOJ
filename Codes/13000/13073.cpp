#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll sum(int x) {
    return (ll) x * (x + 1) / 2;
}

inline ll odd_sum(int x) {
    return (ll) x * x;
}

inline ll even_sum(int x) {
    return (ll) x * x + x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        cout << sum(x) << ' ' << odd_sum(x) << ' ' << even_sum(x) << '\n';
    }
    return 0;
}
