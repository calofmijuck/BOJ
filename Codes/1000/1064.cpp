#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long double ld;

void init_point(pii& p) {
    cin >> p.first >> p.second;
}

bool check_colinear(pii& a, pii& b, pii& c) {
    return (b.second - a.second) * (c.first - b.first) == (c.second - b.second) * (b.first - a.first);
}

ld dist(pii& a, pii& b) {
    return hypot((ld) b.first - a.first, (ld) b.second - a.second);
}

ld perimeter(pii& a, pii& b, pii& c) {
    return 2 * (dist(a, b) + dist(b, c));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pii a, b, c;
    init_point(a);
    init_point(b);
    init_point(c);

    if (check_colinear(a, b, c)) {
        cout << -1;
        return 0;
    }

    ld perimeters[3] = {
        perimeter(a, c, b), perimeter(a, b, c), perimeter(b, a, c)
    };
    sort(perimeters, perimeters + 3);

    cout << fixed << setprecision(12) << perimeters[2] - perimeters[0];
    return 0;
}
