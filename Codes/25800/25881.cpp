#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int base_rate, modified_rate;
    cin >> base_rate >> modified_rate;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int usage;
        cin >> usage;

        int charge = min(usage, 1000) * base_rate + max(usage - 1000, 0) * modified_rate;
        cout << usage << ' ' << charge << '\n';
    }
    return 0;
}
