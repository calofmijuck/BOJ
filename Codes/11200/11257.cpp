#include <bits/stdc++.h>
using namespace std;

const double threshold = 0.3;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string number;
    int strategy, management, technology;
    for (int i = 0; i < n; ++i) {
        cin >> number >> strategy >> management >> technology;
        int total = strategy + management + technology;

        bool fail = strategy < 35 * threshold or management < 25 * threshold or technology < 40 * threshold;
        fail = fail or (total < 55);

        cout << number << ' ' << total << ' ' << (fail ? "FAIL" : "PASS") << '\n';
    }
    return 0;
}
