#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> original(n);
    for (int i = 0; i < n; ++i) {
        cin >> original[i];
    }

    vector<string> inverted(n);
    for (int i = 0; i < n; ++i) {
        cin >> inverted[i];
    }

    int wrong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (original[i][j] == inverted[i][j]) {
                wrong++;
            }
        }
    }

    cout << wrong;
    return 0;
}
