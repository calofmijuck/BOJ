#include <bits/stdc++.h>
using namespace std;

const int MIN_BALANCE = -200;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int balance, amount;
    string operation;

    while (true) {
        cin >> balance >> operation >> amount;
        if (balance == 0 and operation[0] == 'W' and amount == 0) {
            break;
        }

        if (operation[0] == 'W') {
            if (balance - amount < MIN_BALANCE) {
                cout << "Not allowed\n";
            } else {
                cout << balance - amount << '\n';
            }
        } else {
            cout << balance + amount << '\n';
        }
    }
    return 0;
}
