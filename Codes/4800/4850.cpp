#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long baskets, weights, difference, total;
    while (cin >> baskets) {
        cin >> weights >> difference >> total;
        long long coins = (baskets - 1) * baskets / 2;

        long long value = weights * coins - total;
        if (value == 0) {
            cout << baskets << '\n';
        } else {
            cout << value / difference << '\n';
        }
    }
    return 0;
}
