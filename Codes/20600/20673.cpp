#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cases, hospital;
    cin >> cases >> hospital;

    if (cases <= 50 and hospital <= 10) {
        cout << "White";
    } else if (hospital > 30) {
        cout << "Red";
    } else {
        cout << "Yellow";
    }
    return 0;
}
