#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;
typedef pair<point, point> line_segment;

ll sgn(ll x) {
    return (x > 0) - (x < 0);
}

point subtract(point x, point y) {
    return {x.first - y.first, x.second - y.second};
}

ll cross_product(point x, point y) {
    return x.first * y.second - x.second * y.first;
}

ll ccw(point a, point b, point c) {
    ll result = cross_product(subtract(b, a), subtract(c, b));
    return sgn(result);
}

bool check_intersection(line_segment l, line_segment m) {
    int x = ccw(l.first, l.second, m.first) * ccw(l.first, l.second, m.second);
    int y = ccw(m.first, m.second, l.first) * ccw(m.first, m.second, l.second);
    if (x == 0 && y == 0) {
        if (l.first > l.second) {
            swap(l.first, l.second);
        }
        if (m.first > m.second) {
            swap(m.first, m.second);
        }
        return l.first <= m.second && m.first <= l.second;
    }
    return x <= 0 && y <= 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    line_segment l, m;
    cin >> l.first.first >> l.first.second >> l.second.first >> l.second.second;
    cin >> m.first.first >> m.first.second >> m.second.first >> m.second.second;

    cout << check_intersection(l, m);
    return 0;
}
