#include <bits/stdc++.h>
using namespace std;

const long double PI = 3.14159265358979323;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int slice_area, slice_price;
    cin >> slice_area >> slice_price;

    int circular_radius, circular_price;
    cin >> circular_radius >> circular_price;

    double slice_per_dollar = (double) slice_area / slice_price;
    double circular_per_dollar = PI * circular_radius * circular_radius / circular_price;

    if (slice_per_dollar > circular_per_dollar) {
        cout << "Slice of pizza";
    } else {
        cout << "Whole pizza";
    }

    return 0;
}
