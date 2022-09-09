#include <bits/stdc++.h>
using namespace std;

int product(vector<int>& points, vector<int>& count) {
    int sum = 0;
    for (int i = 0; i < (int) count.size(); ++i) {
        sum += points[i % 3] * count[i];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> points(3);
    for (int i = 0; i < (int) points.size(); ++i) {
        cin >> points[i];
    }

    int team, max_score = 0;
    cin >> team;
    for (int i = 0; i < team; ++i) {
        vector<int> count(9);
        for (int j = 0; j < (int) count.size(); ++j) {
            cin >> count[j];
        }

        max_score = max(max_score, product(points, count));
    }

    cout << max_score;
    return 0;
}
