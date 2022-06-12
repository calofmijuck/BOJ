#include <bits/stdc++.h>
using namespace std;

int calculate_width(string& address) {
    int width = address.size() + 1;
    for (char c : address) {
        if (c == '1') {
            width += 2;
        } else if (c == '0') {
            width += 4;
        } else {
            width += 3;
        }
    }
    return width;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string address;
    while (true) {
        cin >> address;
        if (address == "0") {
            break;
        }

        cout << calculate_width(address) << '\n';
    }
    return 0;
}
