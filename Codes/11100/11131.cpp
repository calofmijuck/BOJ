#include <bits/stdc++.h>
using namespace std;

const string BALANCE = "Equilibrium";
const string RIGHT = "Right";
const string LEFT = "Left";

string weight_balance() {
    int weights;
    cin >> weights;

    int net_torque = 0;
    for (int i = 0; i < weights; ++i) {
        int weight;
        cin >> weight;

        net_torque += weight;
    }

    if (net_torque > 0) {
        return RIGHT;
    } else if (net_torque < 0) {
        return LEFT;
    } else {
        return BALANCE;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cout << weight_balance() << '\n';
    }
    return 0;
}
