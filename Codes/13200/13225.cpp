#include <bits/stdc++.h>
using namespace std;

int count_divisors(int n) {
    int divisors = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            divisors++;
        }
    }
    return divisors;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        cout << n << ' ' << count_divisors(n) << '\n';
    }
    return 0;
}
