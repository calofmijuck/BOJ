#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;

    int charge;
    cin >> charge;

    int diff = abs(start_x - end_x) + abs(start_y - end_y) - charge;
    int parity = (start_x + start_y) - (end_x + end_y) - charge;

    if (diff > 0 || parity % 2 != 0) {
        cout << "N";
    } else {
        cout << "Y";
    }

    return 0;
}
