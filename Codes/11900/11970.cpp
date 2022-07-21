#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (c >= b or d <= a) {
        cout << (b - a) + (d - c);
    } else {
        cout << max(b, d) - min(a, c);
    }
    return 0;
}
