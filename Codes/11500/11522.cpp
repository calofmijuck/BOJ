#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sum(ll n) {
    return n * (n + 1) / 2;
}

ll odd_sum(ll n) {
    return n * n;
}

ll even_sum(ll n) {
    return n * (n + 1);
}

void handle_case() {
    int number, n;
    cin >> number >> n;
    cout << number << ' ' << sum(n) << ' ' << odd_sum(n) << ' ' << even_sum(n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cases;
    cin >> cases;

    while (cases--) {
        handle_case();
    }
    return 0;
}
