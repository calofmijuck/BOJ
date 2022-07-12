#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int count;
        string character;

        cin >> count >> character;

        for (int i = 0; i < count; ++i) {
            cout << character[0];
        }

        cout << '\n';
    }
    return 0;
}
