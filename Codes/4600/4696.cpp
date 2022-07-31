#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(2);

    double rate;
    while (true) {
        cin >> rate;
        if (rate == 0) {
            break;
        }

        double total;
        if (rate == 1) {
            total = 5 * rate;
        } else {
            total = (pow(rate, 5) - 1) / (rate - 1);
        }
        cout << fixed << total << '\n';
    }
    return 0;
}
