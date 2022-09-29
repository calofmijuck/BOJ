#include <bits/stdc++.h>
using namespace std;

int digit_sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int low, high, sum;
    cin >> low >> high >> sum;

    int min = high, max = low;
    for (int i = low; i <= high; ++i) {
        if (sum != digit_sum(i)) {
            continue;
        }

        if (i < min) {
            min = i;
        }

        if (i > max) {
            max = i;
        }
    }

    cout << min << '\n' << max;
    return 0;
}
