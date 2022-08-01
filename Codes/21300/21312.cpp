#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> values(3);
    for (int i = 0; i < 3; ++i) {
        cin >> values[i];
    }

    int odd_count = 0;
    for (int i = 0; i < 3; ++i) {
        odd_count += (values[i] % 2 != 0);
    }

    if (odd_count == 0) {
        cout << values[0] * values[1] * values[2];
        return 0;
    }

    int prod = 1;
    for (int i = 0; i < 3; ++i) {
        if (values[i] % 2 != 0) {
            prod *= values[i];
        }
    }
    cout << prod;
    return 0;
}
