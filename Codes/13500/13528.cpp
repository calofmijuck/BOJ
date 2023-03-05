#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(10);

    double cost;
    cin >> cost;

    int count;
    cin >> count;

    double area = 0;
    for (int i = 0; i < count; ++i) {
        double width, length;
        cin >> width >> length;
        area += width * length;
    }

    cout << fixed << cost * area;
    return 0;
}
