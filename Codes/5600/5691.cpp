#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x, y;
    while (true) {
        cin >> x >> y;
        if (x == 0 and y == 0) {
            break;
        }

        cout << 2 * min(x, y) - max(x, y) << '\n';
    }
    return 0;
}
