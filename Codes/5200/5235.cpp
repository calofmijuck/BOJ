#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        int odd_sum = 0, even_sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            if (x % 2 == 0) {
                even_sum += x;
            } else {
                odd_sum += x;
            }
        }

        if (odd_sum > even_sum) {
            cout << "ODD\n";
        } else if (odd_sum < even_sum) {
            cout << "EVEN\n";
        } else {
            cout << "TIE\n";
        }
    }
    return 0;
}
