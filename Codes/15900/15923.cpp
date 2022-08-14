#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int dist(pii& p1, pii& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int perimeter(vector<pii>& points) {
    int result = 0;
    for (int i = 1; i < (int) points.size(); ++i) {
        result += dist(points[i - 1], points[i]);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pii> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    points.push_back(points[0]);

    cout << perimeter(points);
    return 0;
}
