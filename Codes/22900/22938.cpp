#include <bits/stdc++.h>
using namespace std;

using pll = pair<long long, long long>;

double dist(pll& p1, pll& p2) {
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    pll p1, p2;
    long long r1, r2;

    cin >> p1.first >> p1.second >> r1;
    cin >> p2.first >> p2.second >> r2;

    if (dist(p1, p2) < r1 + r2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
