#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0;
    } else {
        if (n % 4 == 0) {
            cout << 2;
        } else {
            cout << 1;
        }
    }
    return 0;
}
