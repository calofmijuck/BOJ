#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tiger = 0, lion = 0;
    string input;
    while (cin >> input) {
        if (input == "Tiger") {
            tiger++;
        } else {
            lion++;
        }
    }

    if (tiger > lion) {
        cout << "Tiger";
    } else {
        cout << "Lion";
    }
    return 0;
}
