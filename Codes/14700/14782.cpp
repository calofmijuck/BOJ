#include <bits/stdc++.h>
using namespace std;

long long sum_of_divisors(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i != 0) {
            continue;
        }

        sum += i;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << sum_of_divisors(n);
    return 0;
}
