#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int students;
        cin >> students;

        unsigned long long total = 0;
        for (int i = 0; i < students; ++i) {
            long long candy;
            cin >> candy;
            total = (total + candy) % students;
        }

        cout << (total == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}
