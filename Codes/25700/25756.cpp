#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(10);

    int n;
    cin >> n;

    double rate = 0;
    for (int i = 0; i < n; ++i) {
        int item = 0;
        cin >> item;

        rate = 1 - (1 - rate) * (1 - 0.01 * item);
        cout << fixed << rate * 100 << '\n';
    }
    return 0;
}
