#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int people, turn;
    cin >> people >> turn;

    turn -= 1;
    turn %= (4 * people - 2);
    if (turn < 2 * people) {
        cout << turn + 1;
    } else {
        turn -= 2 * people;
        cout << (2 * people - turn - 1);
    }
    return 0;
}
