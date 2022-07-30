#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long total = 0;
    while (true) {
        int money;
        cin >> money;

        if (money == -1) {
            break;
        }

        total += money;
    }

    cout << total;
    return 0;
}
