#include <bits/stdc++.h>
using namespace std;

void n_queens(int n) {
    bool odd = n % 2 == 1;
    int r = n % 6;
    if (odd) {
        n_queens(n - 1);
        cout << n << '\n';
        return;
    }

    if (r != 2) {
        for (int i = 1; i <= n / 2; ++i) {
            cout << 2 * i << '\n';
        }
        for (int i = 1; i <= n / 2; ++i) {
            cout << 2 * i - 1 << '\n';
        }
    } else {
        for (int i = 1; i <= n / 2; ++i) {
            int x = 1 + (2 * (i - 1) + n / 2 - 1) % n;
            cout << x << '\n';
        }
        for (int i = n / 2; i >= 1; --i) {
            int x = n - (2 * (i - 1) + n / 2 - 1) % n;
            cout << x << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    n_queens(n);

    return 0;
}
