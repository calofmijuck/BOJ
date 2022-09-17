#include <bits/stdc++.h>
using namespace std;

int net_income(int income) {
    if (income <= 1000000) {
        return income;
    }

    if (income <= 5000000) {
        return int(0.9 * income);
    }

    return int(0.8 * income);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int income;
    while (true) {
        cin >> income;
        if (income == 0) {
            break;
        }

        cout << net_income(income) << '\n';
    }
    return 0;
}
