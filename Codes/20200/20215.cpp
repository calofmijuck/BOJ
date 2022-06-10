#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int width, height;
    cin >> width >> height;

    cout.precision(10);
    cout << fixed << abs(width + height - hypot(width, height));
    return 0;
}
