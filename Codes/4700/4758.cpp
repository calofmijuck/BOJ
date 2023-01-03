#include <bits/stdc++.h>
using namespace std;

bool compare(double speed, int weight, int strength, double value1, int value2, int value3) {
    return speed <= value1 && weight >= value2 && strength >= value3;
}

void get_position(double speed, int weight, int strength) {
    bool exists = false;
    if (compare(speed, weight, strength, 4.5, 150, 200)) {
        exists = true;
        cout << "Wide Receiver ";
    }
    if (compare(speed, weight, strength, 6.0, 300, 500)) {
        exists = true;
        cout << "Lineman ";
    }
    if (compare(speed, weight, strength, 5.0, 200, 300)) {
        exists = true;
        cout << "Quarterback ";
    }

    if (!exists) {
        cout << "No positions";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    double speed;
    int weight, strength;
    while (true) {
        cin >> speed >> weight >> strength;
        if (speed == 0 && weight == 0 && strength == 0) {
            break;
        }

        get_position(speed, weight, strength);
    }
    return 0;
}
