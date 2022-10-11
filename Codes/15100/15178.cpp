#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int sum = 0, angle;
        for (int i = 0; i < 3; ++i) {
            cin >> angle;
            cout << angle << ' ';
            sum += angle;
        }

        if (sum == 180) {
            cout << "Seems OK\n";
        } else {
            cout << "Check\n";
        }
    }
    return 0;
}
