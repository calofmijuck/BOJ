#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T>
T sgn(T x) {
    return (x > 0) - (x < 0);
}

template <typename T>
class line_segment {
public:
    class point {
    public:
        T x, y;

        static point subtract(point p1, point p2) {
            return {p1.x - p2.x, p1.y - p2.y};
        }

        static T cross_product(point p1, point p2) {
            return p1.x * p2.y - p1.y * p2.x;
        }

        static T ccw(point p1, point p2, point p3) {
            return sgn(cross_product(subtract(p2, p1), subtract(p3, p2)));
        }

        bool operator==(const point& other) {
            return x == other.x && y == other.y;
        }

        bool operator<(const point& other) {
            return (x < other.x) || (!(other.x < x) && y < other.y);
        }

        bool operator<=(const point& other) {
            return (x < other.x) || (!(other.x < x) && y <= other.y);
        }
    } p, q;

    static bool check_intersection(line_segment<T> l1, line_segment<T> l2) {
        int x = point::ccw(l1.p, l1.q, l2.p) * point::ccw(l1.p, l1.q, l2.q);
        int y = point::ccw(l2.p, l2.q, l1.p) * point::ccw(l2.p, l2.q, l1.q);
        if (x == 0 && y == 0) {
            if (l1.q < l1.p) {
                swap(l1.p, l1.q);
            }
            if (l2.q < l2.p) {
                swap(l2.p, l2.q);
            }
            return l1.p <= l2.q && l2.p <= l1.q;
        }
        return x <= 0 && y <= 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    line_segment<ll> l, m;
    cin >> l.p.x >> l.p.y >> l.q.x >> l.q.y;
    cin >> m.p.x >> m.p.y >> m.q.x >> m.q.y;

    cout << line_segment<ll>::check_intersection(l, m);
    return 0;
}
