#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int one = 0, two = 0;
    for (int i = 0; i < 3; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            one++;
        } else {
            two++;
        }
    }

    if (one > two) {
        cout << 1;
    } else {
        cout << 2;
    }

    return 0;
}
