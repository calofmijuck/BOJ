#include <bits/stdc++.h>
using namespace std;

int get_group(int wins) {
    if (wins >= 5) {
        return 1;
    } else if (wins >= 3) {
        return 2;
    } else if (wins >= 1) {
        return 3;
    } else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int wins = 0;
    for (int i = 0; i < 6; ++i) {
        string s;
        cin >> s;

        if (s[0] == 'W') {
            wins++;
        }
    }

    cout << get_group(wins);
    return 0;
}
