#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << m * (i - 1) + j;

            if (j != m) {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
