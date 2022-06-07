#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int left, right;
    cin >> left >> right;

    if (left == 0 and right == 0) {
        cout << "Not a moose";
    } else if (left == right) {
        cout << "Even " << left + right;
    } else {
        cout << "Odd " << 2 * max(left, right);
    }
    return 0;
}
