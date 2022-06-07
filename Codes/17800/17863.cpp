#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int phone_number;
    cin >> phone_number;

    int prefix = (phone_number) / 10000;
    if (prefix == 555) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
