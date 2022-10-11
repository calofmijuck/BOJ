#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        cout << n * (n + 1) / 2 * (2 * n + 1) / 3 << '\n';
    }
    return 0;
}
