#include <bits/stdc++.h>
using namespace std;

int multiply_digits(int x) {
    int product = 1;
    while (x > 0) {
        product *= (x % 10);
        x /= 10;
    }
    return product;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x;
    cin >> x;

    int count = 0;
    while (x >= 10) {
        x = multiply_digits(x);
        count++;
    }

    cout << count;
    return 0;
}
