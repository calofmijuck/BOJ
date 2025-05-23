#include <bits/stdc++.h>
using namespace std;

string solve(pair<int, int>& curr, vector<pair<int, int>>& ship_left, vector<pair<int, int>>& ship_right) {
    string result = "No";
    for (int i = 0; i < (int) ship_left.size(); ++i) {
        auto left = ship_left[i];
        auto right = ship_right[i];

        long long t = (long long) (curr.first - right.first) * (curr.second - left.second) - (long long) (curr.first - left.first) * (curr.second - right.second);
        if (t == 0) {
            result = "Yes";
            break;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    pair<int, int> curr;
    vector<pair<int, int>> ship_left(n), ship_right(n);

    cin >> n >> curr.first >> curr.second;

    ship_left.resize(n);
    ship_right.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> ship_left[i].first >> ship_left[i].second;
        cin >> ship_right[i].first >> ship_right[i].second;
    }
    cout << solve(curr, ship_left, ship_right);
    return 0;
}
