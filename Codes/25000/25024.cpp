#include <bits/stdc++.h>
using namespace std;

bool is_time(int x, int y) {
    return 0 <= x and x <= 23 and 0 <= y and y <= 59;
}

bool is_date(int x, int y) {
    if (x < 1 or x > 12) {
        return false;
    }

    if (x == 2) {
        return 1 <= y and y <= 29;
    }

    if (x == 4 or x == 6 or x == 9 or x == 11) {
        return 1 <= y and y <= 30;
    }

    return 1 <= y and y <= 31;
}

string answer(bool b) {
    return b ? "Yes" : "No";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        cout << answer(is_time(x, y)) << ' ' << answer(is_date(x, y)) << '\n';
    }
    return 0;
}
