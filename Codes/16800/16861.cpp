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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    while (true) {
        int sum = digit_sum(n);
        if (n % sum == 0) {
            cout << n;
            break;
        }
        n++;
    }
    return 0;
}
