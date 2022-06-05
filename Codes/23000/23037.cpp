#include <bits/stdc++.h>
using namespace std;

int fifth_power_sum(int n) {
    int sum = 0;
    while (n > 0) {
        int r = n % 10;
        sum += pow(r, 5);
        n /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    cout << fifth_power_sum(n);
    return 0;
}
