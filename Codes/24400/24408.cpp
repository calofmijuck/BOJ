#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int base = 0;
    bool new_game = true;
    while (n--) {
        int x;
        cin >> x;

        if (new_game) {
            base = x;
            new_game = false;
            continue;
        }

        if (x % base == 0) {
            cout << x << '\n';
            new_game = true;
        }
    }
    return 0;
}
