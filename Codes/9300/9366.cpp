#include <bits/stdc++.h>
using namespace std;

string triangle_type(vector<int>& side) {
    sort(begin(side), end(side));

    if (side[0] == side[1] and side[1] == side[2]) {
        return "equilateral";
    }

    if (side[0] + side[1] <= side[2]) {
        return "invalid!";
    }

    if (side[0] == side[1] or side[1] == side[2] or side[2] == side[0]) {
        return "isosceles";
    }

    return "scalene";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    vector<int> sides(3);
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> sides[j];
        }

        cout << "Case #" << i << ": " << triangle_type(sides) << '\n';
    }
    return 0;
}
