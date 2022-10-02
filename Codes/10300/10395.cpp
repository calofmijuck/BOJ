#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n = 5;
    vector<int> x(n), y(n);

    for (int i = 0; i < 5; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < 5; ++i) {
        cin >> y[i];
    }

    bool compatible = true;
    for (int i = 0; i < 5; ++i) {
        compatible &= (x[i] != y[i]);
    }

    if (compatible) {
        cout << "Y";
    } else {
        cout << "N";
    }
    return 0;
}
