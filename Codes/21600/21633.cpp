#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    cout.precision(2);
    cout << fixed << min(max(100.0, 25 + 0.01 * k), 2000.0);
    return 0;
}
