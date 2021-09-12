#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    double h, w;
    cin >> h >> w;

    // Brute Force
    double maximum = 0;
    if (h <= w) {
        maximum = max(maximum, h / 2);
    }
    if (w <= h) {
        maximum = max(maximum, w / 2);
    }
    if (w / 3 <= h) {
        maximum = max(maximum, w / 3);
    }
    if (h / 3 <= w) {
        maximum = max(maximum, h / 3);
    }
    if (w * 3 <= h) {
        maximum = max(maximum, w);
    }
    if (h * 3 <= w) {
        maximum = max(maximum, h);
    }
    cout << fixed << setprecision(5) << maximum;
    return 0;
}
