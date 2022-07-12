#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cups, location, moves;
    cin >> cups >> location >> moves;

    for (int i = 0; i < moves; ++i) {
        int x, y;
        cin >> x >> y;

        if (location == x) {
            location = y;
        } else if (location == y) {
            location = x;
        }
    }

    cout << location;
    return 0;
}
