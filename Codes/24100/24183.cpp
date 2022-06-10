#include <bits/stdc++.h>
using namespace std;

const double c4 = 0.229 * 0.324;
const double a3 = 0.297 * 0.42;
const double a4 = 0.21 * 0.297;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> weights(3);
    for (int i = 0; i < 3; ++i) {
        cin >> weights[i];
    }

    cout.precision(10);
    cout << fixed << 2 * c4 * weights[0] + 2 * a3 * weights[1] + a4 * weights[2];
    return 0;
}
