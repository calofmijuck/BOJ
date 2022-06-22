#include <bits/stdc++.h>
using namespace std;

int sum_of_divisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << 5 * sum_of_divisors(n) - 24;
    return 0;
}
