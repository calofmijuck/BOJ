#include <bits/stdc++.h>
using namespace std;

int get_proper_divisor_sum(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

void handle_case() {
    int x;
    cin >> x;

    int proper_divisor_sum = get_proper_divisor_sum(x);
    if (proper_divisor_sum < x) {
        cout << x << " is a deficient number.\n";
    } else if (proper_divisor_sum > x) {
        cout << x << " is an abundant number.\n";
    } else {
        cout << x << " is a perfect number.\n";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        handle_case();
    }
    return 0;
}
