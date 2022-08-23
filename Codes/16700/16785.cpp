#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int weekly = 7 * a + b;
    int days = c / weekly * 7;
    int remaining = c % weekly;

    if (remaining == 0) {
        cout << days;
        return 0;
    }

    int coins = 0;
    for (int i = 1; i <= 7; ++i) {
        coins += a;
        if (coins >= remaining) {
            cout << days + i;
            return 0;
        }
    }
    cout << days + 7;
    return 0;
}
