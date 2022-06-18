#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, count, velocity, fuel, rate;
    cin >> t;
    while (t--) {
        int ships, distance, count = 0;
        cin >> ships >> distance;

        int velocity, fuel, rate;
        for (int i = 0; i < ships; ++i) {
            cin >> velocity >> fuel >> rate;
            if ((double) fuel / rate * velocity >= distance) {
                count++;
            }
        }

        cout << count << '\n';
    }
    return 0;
}
