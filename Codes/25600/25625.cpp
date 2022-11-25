#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int trip_time, location;
    cin >> trip_time >> location;
    if (location <= trip_time) {
        cout << location + trip_time;
    } else {
        cout << location - trip_time;
    }
    return 0;
}
