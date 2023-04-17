#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(10);

    int flavors;
    cin >> flavors;

    for (int i = 0; i < flavors; ++i) {
        double price, change;
        cin >> price >> change;

        cout << fixed << double(price) / (change / 100.0 + 1) << '\n';
    }
    return 0;
}
