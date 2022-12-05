#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll donation() {
    int missions;
    cin >> missions;

    vector<vector<int>> pot(missions);
    for (int i = 0; i < missions; ++i) {
        pot[i].resize(3);
        for (int j = 0; j < 3; ++j) {
            cin >> pot[i][j];
        }
    }

    ll kill, death, assist;
    cin >> kill >> death >> assist;

    ll total = 0;
    for (vector<int>& mission : pot) {
        ll result = kill * mission[0] - death * mission[1] + assist * mission[2];
        if (result > 0) {
            total += result;
        }
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int games;
    cin >> games;

    while (games--) {
        cout << donation() << '\n';
    }
    return 0;
}
