#include <bits/stdc++.h>
using namespace std;

struct game_data {
    double a;
    double b;
    double c;
    bool field;

    int get_score(double p) {
        double diff = (field ? 1 : -1) * (p - b);
        return (int) floor(a * pow(diff, c));
    }
};

vector<game_data> games = {
    {9.23076, 26.7, 1.835, false},
    {1.84523, 75, 1.348, true},
    {56.0211, 1.5, 1.05, true},
    {4.99087, 42.5, 1.81, false},
    {0.188807, 210, 1.41, true},
    {15.9803, 3.8, 1.04, true},
    {0.11193, 254, 1.88, false}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vector<int> record(7);
        for (int i = 0; i < (int) record.size(); ++i) {
            cin >> record[i];
        }

        int sum = 0;
        for (int i = 0; i < (int) record.size(); ++i) {
            sum += games[i].get_score(record[i]);
        }
        cout << sum << '\n';
    }
    return 0;
}
