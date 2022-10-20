#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int contests;
    cin >> contests;

    int total = 0, prize;
    for (int i = 0; i < contests; ++i) {
        cin >> prize;
        total += prize;
    }

    if (total % 3 == 0) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}
