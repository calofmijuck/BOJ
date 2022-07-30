#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int bakery;
    cin >> bakery;

    int min_time = numeric_limits<int>::max();
    for (int i = 0; i < bakery; ++i) {
        int distance, arrival;
        cin >> distance >> arrival;

        if (distance > arrival) {
            continue;
        }

        min_time = min(min_time, arrival);
    }

    if (min_time == numeric_limits<int>::max()) {
        cout << -1;
    } else {
        cout << min_time;
    }
    return 0;
}
