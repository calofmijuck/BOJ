#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int target, left, right;
    cin >> target >> left >> right;

    if (left <= target and target <= right) {
        cout << target;
    } else if (target >= right) {
        cout << right;
    } else if (target <= left) {
        cout << left;
    }
    return 0;
}
