#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if (a != b and a != c) {
        cout << "A";
    } else if (b != a and b != c) {
        cout << "B";
    } else if (c != a and c != b) {
        cout << "C";
    } else {
        cout << "*";
    }
    return 0;
}
