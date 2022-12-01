#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(10);

    int n;
    cin >> n;

    long double volume = 0;
    for (int i = 0; i < n; ++i) {
        double side;
        cin >> side;
        volume += side * side * side;
    }

    cout << fixed << cbrt(volume);
    return 0;
}
