#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int steps = 0;
        for (char c : s) {
            if (c == 'U') {
                steps++;
            } else {
                break;
            }
        }

        cout << steps << '\n';
    }
    return 0;
}
