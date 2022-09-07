#include <bits/stdc++.h>
using namespace std;

void fizz_buzz(int n, int x, int y) {
    bool divisible_x = n % x == 0;
    bool divisible_y = n % y == 0;

    if (divisible_x) {
        cout << "Fizz";
    }

    if (divisible_y) {
        cout << "Buzz";
    }

    if (!divisible_x and !divisible_y) {
        cout << n;
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x, y, n;
    cin >> x >> y >> n;

    for (int i = 1; i <= n; ++i) {
        fizz_buzz(i, x, y);
    }
    return 0;
}
