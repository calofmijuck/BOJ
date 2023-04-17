#include <bits/stdc++.h>
using namespace std;

inline double volume(double radius) {
    return M_PI * 4 / 3 * radius * radius * radius;
}

string solve() {
    int balloons;
    double weight;
    cin >> balloons >> weight;

    double buoyant = 0;
    for (int i = 0; i < balloons; ++i) {
        double radius;
        cin >> radius;

        buoyant += volume(radius);
    }

    return (buoyant / 1000 > weight) ? "Yes" : "No";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        cout << "Data Set " << i << ":\n";
        cout << solve() << "\n\n";
    }
    return 0;
}
