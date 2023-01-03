#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        cout << n * (n + 1) / 2 << '\n';
    }
    return 0;
}
