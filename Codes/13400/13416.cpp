#include <bits/stdc++.h>
using namespace std;

int max_profit() {
    int days;
    cin >> days;

    int profit = 0;
    for (int i = 0; i < days; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        profit += max({ 0, a, b, c });
    }
    return profit;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << max_profit() << '\n';
    }
    return 0;
}
