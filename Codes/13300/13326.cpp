#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> point;
vector<int> idx;
int n, r, b, left_mx[5005], right_mx[5005];

inline int dist(int i, int j) {
    pii x = point[i], y = point[j];
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

void find_farthest_points() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(dist(r, b) < dist(i, j)) {
                r = i;
                b = j;
            }
        }
    }
}

bool cmp(int x, int y) {
    return dist(r, x) < dist(r, y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    point.resize(n);
    idx.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> point[i].first >> point[i].second;
        idx[i] = i;
    }
    find_farthest_points();
    sort(idx.begin(), idx.end(), cmp);

    // calculate diameter from the rightmost point
    for(int i = n - 2; i >= 0; --i) {
        left_mx[i] = left_mx[i + 1];
        for(int j = n - 1; j > i; --j) {
            left_mx[i] = max(left_mx[i], dist(idx[i], idx[j]));
        }
    }
    // calculate diameter from the leftmost point
    for(int i = 1; i < n; ++i) {
        right_mx[i] = right_mx[i - 1];
        for(int j = 0; j < i; ++j) {
            right_mx[i] = max(right_mx[i], dist(idx[i - 1], idx[j]));
        }
    }
    double ans = (double) 0x3f3f3f3f;
    for(int i = 0; i < n; ++i) {
        ans = min(ans, sqrt(left_mx[i]) + sqrt(right_mx[i]));
    }
    cout << fixed;
    cout.precision(10);
    cout << ans;
    return 0;
}