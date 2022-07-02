#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int ships, speed, days;
        cin >> ships >> speed >> days;

        int repay = 0;
        for (int j = 0; j < ships; ++j) {
            int distance, value;
            cin >> distance >> value;

            if (distance <= speed * days) {
                repay += value;
            }
        }

        cout << "Data Set " << i << ":\n";
        cout << repay << "\n\n";
    }
    return 0;
}
