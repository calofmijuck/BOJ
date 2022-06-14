#include <bits/stdc++.h>
using namespace std;

const int END = 999;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    double current, prev;
    cin >> current;

    cout.precision(2);

    do {
        prev = current;
        cin >> current;
        if (current == END) {
            break;
        }

        cout << fixed << current - prev << '\n';
    } while (true);
    return 0;
}
