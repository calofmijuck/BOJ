#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define MAX 0x3f3f3f3f

pll zero = {0, 0}, lowest;

inline pll sub(pll x, pll y) {
    return {x.first - y.first, x.second - y.second};
}

inline ll cross_product(pll x, pll y) {
    return x.first * y.second - x.second * y.first;
}

inline ll ccw(pll prev, pll curr, pll next) {
    return cross_product(sub(curr, prev), sub(next, prev));
}

pll find_lowermost_point(vector<pll>& points) {
    pll ret = {MAX, MAX};
    for(pll p : points) {
        if(p.second < ret.second)
            ret = p;
        else if(p.second == ret.second)
            ret.first = min(ret.first, p.first);
    }
    return ret;
}

vector<pll> graham_scan(const vector<pll>& points) {
    vector<pll> convex_hull;
    for(pll curr : points) {
        while(convex_hull.size() > 1) {
            pll top = convex_hull.back();
            pll next_to_top = convex_hull[convex_hull.size() - 2];
            bool right_turn = ccw(next_to_top, top, curr) <= 0;
            if(right_turn)
                convex_hull.pop_back();
            else
                break;
        }
        convex_hull.push_back(curr);
    }
    return convex_hull;
}

bool cmp_angle(pll x, pll y) {
    ll cross = cross_product(sub(x, lowest), sub(y, lowest));
    if(cross == 0) {
        if(x.second != y.second)
            return x.second < y.second;
        return x.first < y.first;
    }
    return cross > 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<pll> points;
    for(int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    lowest = find_lowermost_point(points);
    sort(points.begin(), points.end(), cmp_angle);
    vector<pll> convex_hull = graham_scan(points);
    cout << convex_hull.size();
    return 0;
}
