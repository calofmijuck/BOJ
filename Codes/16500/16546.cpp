#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; ++i) {
        int rank;
        cin >> rank;
        sum -= rank;
    }

    cout << sum;
    return 0;
}
