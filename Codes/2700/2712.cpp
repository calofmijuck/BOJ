#include <bits/stdc++.h>
using namespace std;

map<string, pair<double, string>> converter = {
    { "kg", { 2.2046, "lb" }},
    { "lb", { 0.4536, "kg" }},
    { "l", { 0.2642, "g" }},
    { "g", { 3.7854, "l" }},
};

void convert(double value, string& unit) {
    auto [factor, converted_unit] = converter[unit];
    cout << fixed << factor * value << ' ' << converted_unit << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(4);

    int t;
    cin >> t;

    double value;
    string unit;
    while (t--) {
        cin >> value >> unit;
        convert(value, unit);
    }
    return 0;
}
