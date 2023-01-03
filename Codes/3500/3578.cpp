#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 1;
        return 0;
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    if (n % 2 != 0) {
        cout << 4;
    }

    int count = n / 2;
    for (int i = 0; i < count; ++i) {
        cout << 8;
    }
    return 0;
}
