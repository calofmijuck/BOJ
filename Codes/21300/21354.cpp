#include <bits/stdc++.h>
using namespace std;

const int apple_cost = 7;
const int pear_cost = 13;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int apple, pear;
    cin >> apple >> pear;

    int diff = apple_cost * apple - pear_cost * pear;
    if (diff > 0) {
        cout << "Axel";
    } else if (diff < 0) {
        cout << "Petra";
    } else {
        cout << "lika";
    }

    return 0;
}
