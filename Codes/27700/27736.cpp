#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int people;
    cin >> people;

    int positive = 0, negative = 0, zero = 0;
    for (int i = 0; i < people; ++i) {
        int x;
        cin >> x;

        if (x > 0) {
            positive++;
        } else if (x < 0) {
            negative++;
        } else {
            zero++;
        }
    }

    if (zero >= (people + 1) / 2) {
        cout << "INVALID";
    } else if (positive > negative) {
        cout << "APPROVED";
    } else {
        cout << "REJECTED";
    }
    return 0;
}
