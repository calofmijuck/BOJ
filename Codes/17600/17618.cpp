#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int count_numbers(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        int sum = digit_sum(i);
        if (i % sum == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    cout << count_numbers(n);
    return 0;
}
