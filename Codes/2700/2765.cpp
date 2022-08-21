#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415927;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(2);

    int tc = 1;
    double radius, rotations, seconds;
    while (true) {
        cin >> radius >> rotations >> seconds;
        if (rotations == 0) {
            break;
        }

        double distance = PI * radius / 12 / 5280 * rotations;
        double mph = distance / seconds * 3600;

        cout << fixed << "Trip #" << tc << ": " << distance << ' ' << mph << '\n';
        tc++;
    }
    return 0;
}
