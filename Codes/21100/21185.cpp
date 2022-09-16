#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int remainder = n % 4;
    switch (remainder) {
        case 0:
            cout << "Even";
            break;
        case 2:
            cout << "Odd";
            break;
        case 1:
        case 3:
            cout << "Either";
            break;
        default:
            break;
    }
    return 0;
}
