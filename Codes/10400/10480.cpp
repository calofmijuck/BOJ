#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        if (x % 2 == 0) {
            cout << x << " is even\n";
        } else {
            cout << x << " is odd\n";
        }
    }
    return 0;
}
