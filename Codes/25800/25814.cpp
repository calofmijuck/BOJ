#include <bits/stdc++.h>
using namespace std;

int weight(int n) {
    int digits = 0, sum = 0;
    while (n > 0) {
        digits++;

        sum += n % 10;
        n /= 10;
    }
    return digits * sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x, y;
    cin >> x >> y;

    int x_weight = weight(x), y_weight = weight(y);
    if (x_weight > y_weight) {
        cout << 1;
    } else if (x_weight < y_weight) {
        cout << 2;
    } else {
        cout << 0;
    }
    return 0;
}
