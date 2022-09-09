#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long k, n;
    cin >> k >> n;

    if (n == 1) {
        cout << -1;
        return 0;
    }

    cout << (long long) ceil((long double) k / (n - 1) * n);
    return 0;
}
