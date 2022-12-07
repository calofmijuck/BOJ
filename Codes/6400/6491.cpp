#include <bits/stdc++.h>
using namespace std;

string PERFECT = "PERFECT";
string DEFICIENT = "DEFICIENT";
string ABUNDANT = "ABUNDANT";

string check_sum_of_divisors(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return PERFECT;
    } else if (sum > n) {
        return ABUNDANT;
    } else {
        return DEFICIENT;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        cout << n << ' ' << check_sum_of_divisors(n) << '\n';
    }
    return 0;
}
