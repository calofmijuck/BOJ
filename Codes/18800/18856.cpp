#include <bits/stdc++.h>
using namespace std;

const int END_PRIME = 997;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << n << '\n';

    cout << 1 << ' ' << 2 << ' ';
    for (int i = 2; i < n - 1; ++i) {
        cout << i + 1 << ' ';
    }
    cout << END_PRIME;
    return 0;
}
