#include <bits/stdc++.h>
using namespace std;

const double gallon_to_liter = 3.785411784;
const double mile_to_meter = 1609.344;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    double miles_per_gallon;
    cin >> miles_per_gallon;

    cout.precision(10);
    cout << fixed << 100000 * gallon_to_liter / mile_to_meter / miles_per_gallon;
    return 0;
}
