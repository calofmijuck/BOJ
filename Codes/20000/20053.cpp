#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int min = numeric_limits<int>::max();
        int max = numeric_limits<int>::min();
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            if (x < min) {
                min = x;
            }

            if (x > max) {
                max = x;
            }
        }

        cout << min << ' ' << max << '\n';
    }
    return 0;
}
