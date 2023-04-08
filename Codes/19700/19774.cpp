#include <bits/stdc++.h>
using namespace std;

bool check(int password) {
    int ab = password / 100;
    int cd = password % 100;

    return (ab * ab + cd * cd) % 7 == 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int password;
        cin >> password;

        if (check(password)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
