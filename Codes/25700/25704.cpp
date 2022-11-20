#include <bits/stdc++.h>
using namespace std;

int payment(int n, int price) {
    int smallest = price;
    if (n >= 5) {
        smallest = min(smallest, price - 500);
    }
    if (n >= 10) {
        smallest = min(smallest, price / 10 * 9);
    }
    if (n >= 15) {
        smallest = min(smallest, price - 2000);
    }
    if (n >= 20) {
        smallest = min(smallest, price / 100 * 75);
    }
    return max(smallest, 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, price;
    cin >> n >> price;

    cout << payment(n, price);
    return 0;
}
