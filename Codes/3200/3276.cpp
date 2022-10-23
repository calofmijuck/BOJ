#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        if (i * i >= n) {
            cout << i << ' ' << i;
            break;
        } else if (i * (i + 1) >= n) {
            cout << i << ' ' << i + 1;
            break;
        }
    }
    return 0;
}
