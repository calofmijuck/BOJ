#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(7);

    int rooms, cost_per_meter;
    cin >> rooms >> cost_per_meter;

    int total_area = 0, total_bedroom_area = 0, total_balcony_area = 0;
    for (int i = 0; i < rooms; ++i) {
        int area;
        string type;
        cin >> area >> type;

        total_area += area;
        if (type == "bedroom") {
            total_bedroom_area += area;
        } else if (type == "balcony") {
            total_balcony_area += area;
        }
    }

    cout << total_area << '\n' << total_bedroom_area << '\n';

    double cost = (total_area - 0.5 * total_balcony_area) * cost_per_meter;
    cout << fixed << cost;
    return 0;
}
