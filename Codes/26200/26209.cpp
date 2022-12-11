#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int bit;
    for (int i = 0; i < 8; ++i) {
        cin >> bit;
        if (bit != 0 && bit != 1) {
            cout << 'F';
            return 0;
        }
    }
    cout << 'S';
    return 0;
}
