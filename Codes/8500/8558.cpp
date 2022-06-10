#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n >= 5) {
        cout << 0;
        return 0;
    }

    int product = 1;
    for (int i = 1; i <= n; ++i) {
        product *= i;
    }

    cout << product % 10;
    return 0;
}
