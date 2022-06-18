#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int period;
        cin >> period;

        int max_late = 0;
        while (max_late + max_late * max_late <= period) {
            max_late++;
        }

        cout << max_late - 1 << '\n';
    }
    return 0;
}
