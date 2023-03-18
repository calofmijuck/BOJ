#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if (m >= k) {
        cout << n * (m / k + k - 1);
    } else {
        cout << n * m;
    }
    return 0;
}
