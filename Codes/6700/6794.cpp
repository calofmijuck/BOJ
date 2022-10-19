#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    if (n <= 5) {
        cout << n / 2 + 1;
    } else {
        cout << (10 - n) / 2 + 1;
    }
    return 0;
}
