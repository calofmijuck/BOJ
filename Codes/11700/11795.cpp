#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int packages[3] = {0};
    for (int i = 0; i < n; ++i) {
        int donation = 0;
        int min_packages = numeric_limits<int>::max();
        for (int j = 0; j < 3; ++j) {
            cin >> donation;
            packages[j] += donation;
            min_packages = min(min_packages, packages[j]);
        }

        if (min_packages < 30) {
            cout << "NO\n";
            continue;
        }

        cout << min_packages << '\n';
        for (int j = 0; j < 3; ++j) {
            packages[j] -= min_packages;
        }
    }
    return 0;
}
