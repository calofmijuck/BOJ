#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int boiling_temperature;
    cin >> boiling_temperature;

    int pressure = 5 * boiling_temperature - 400;
    cout << pressure << '\n';
    if (pressure < 100) {
        cout << 1;
    } else if (pressure == 100) {
        cout << 0;
    } else {
        cout << -1;
    }
    return 0;
}
