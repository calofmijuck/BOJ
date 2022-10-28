#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int l1_distance(pii& p1, pii& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    pii current;
    int n;
    cin >> current.first >> current.second >> n;

    pii closest;
    int min_dist = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        pii taxi;
        cin >> taxi.first >> taxi.second;

        int dist = l1_distance(current, taxi);
        if (dist < min_dist) {
            min_dist = dist;
            closest = taxi;
        }
    }
    cout << closest.first << ' ' << closest.second;
    return 0;
}
