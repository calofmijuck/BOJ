#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int monthly, months;
    cin >> monthly >> months;

    int remaining = monthly;
    for (int i = 0; i < months; ++i) {
        int spend;
        cin >> spend;
        remaining -= spend;
        remaining += monthly;
    }
    cout << remaining;
    return 0;
}
