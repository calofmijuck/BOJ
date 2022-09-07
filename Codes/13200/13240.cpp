#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2 == 0) {
                cout << '*';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
    return 0;
}
