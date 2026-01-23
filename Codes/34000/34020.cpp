#include <bits/stdc++.h>
using namespace std;

double solve(vector<int>& ratings) {
    int n = ratings.size();
    sort(begin(ratings), end(ratings));
    reverse(begin(ratings), end(ratings));

    double avg = ratings.back();
    ratings.pop_back();

    for (int i = 1; i < n; ++i) {
        int smallest = ratings.back();
        ratings.pop_back();
        avg = (avg + smallest) / 2;
    }
    return avg;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> ratings(n);
    for (auto& rating : ratings) {
        cin >> rating;
    }

    cout << setprecision(10) << solve(ratings);

    return 0;
}
