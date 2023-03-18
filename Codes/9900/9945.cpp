#include <bits/stdc++.h>
using namespace std;

pair<double, double> calculate(int points) {
    long long mass_sum = 0;
    long long weighted_x = 0, weighted_y = 0;

    for (int i = 0; i < points; ++i) {
        int mass, x, y;
        cin >> x >> y >> mass;

        mass_sum += mass;
        weighted_x += mass * x;
        weighted_y += mass * y;
    }

    return { double(weighted_x) / mass_sum, double(weighted_y) / mass_sum };
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(2);
    for (int i = 1; true; ++i) {
        int points;
        cin >> points;

        if (points < 0) {
            break;
        }

        cout << "Case " << i << ": ";

        pair<double, double> center_of_mass = calculate(points);
        cout << fixed << center_of_mass.first << ' ' << center_of_mass.second << '\n';
    }
    return 0;
}
