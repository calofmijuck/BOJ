#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 1e6;

int nearest_int(int b, int n) {
    int nearest = 0, diff = numeric_limits<int>::max();
    int limit = pow(MAX_A, 1.0 / n) + 1;
    for (int i = 1; i <= limit; ++i) {
        int power = pow(i, n);
        int current_diff = abs(b - power);
        if (current_diff <= diff) {
            nearest = i;
            diff = current_diff;
        }
    }
    return nearest;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int b, n;
    while (true) {
        cin >> b >> n;
        if (b == 0 and n == 0) {
            break;
        }

        cout << nearest_int(b, n) << '\n';
    }
    return 0;
}
