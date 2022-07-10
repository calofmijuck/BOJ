#include <bits/stdc++.h>
using namespace std;

int calculate(int d) {
    int k = int(ceil(sqrt(d))) - 1;
    if (k * (k + 1) < d) {
        return 2 * k + 1;
    } else {
        return 2 * k;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        cout << calculate(y - x) << '\n';
    }
    return 0;
}
