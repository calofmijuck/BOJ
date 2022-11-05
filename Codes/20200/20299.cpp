#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> qualified_teams;

bool is_qualified(vector<int>& rating, int sum, int threshold) {
    int rating_sum = 0;
    for (int e : rating) {
        rating_sum += e;
        if (e < threshold) {
            return false;
        }
    }
    return rating_sum >= sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, sum, threshold;
    cin >> n >> sum >> threshold;

    for (int i = 0; i < n; ++i) {
        vector<int> rating(3);
        for (int j = 0; j < 3; ++j) {
            cin >> rating[j];
        }

        bool qualified = is_qualified(rating, sum, threshold);
        if (qualified) {
            qualified_teams.push_back(rating);
        }
    }

    cout << qualified_teams.size() << '\n';
    for (vector<int>& team : qualified_teams) {
        for (int e : team) {
            cout << e << ' ';
        }
    }
    return 0;
}
