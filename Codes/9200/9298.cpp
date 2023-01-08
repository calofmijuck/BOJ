#include <bits/stdc++.h>
using namespace std;

pair<double, double> calculate_fence() {
    int ants;
    scanf("%d", &ants);

    double x_min = 1000, x_max = -1000;
    double y_min = 1000, y_max = -1000;
    for (int i = 0; i < ants; ++i) {
        double x, y;
        scanf("%lf %lf", &x, &y);

        x_min = min(x_min, x);
        x_max = max(x_max, x);
        y_min = min(y_min, y);
        y_max = max(y_max, y);
    }

    double perimeter = 2 * (x_max - x_min + y_max - y_min);
    double area = (x_max - x_min) * (y_max - y_min);
    return make_pair(area, perimeter);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        auto [area, perimeter] = calculate_fence();
        printf("Case %d: Area %.10lf, Perimeter %.10lf\n", t, area, perimeter);
    }
    return 0;
}
