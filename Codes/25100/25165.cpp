#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m, n, column, direction;
    pii monster;
    cin >> m >> n >> column >> direction >> monster.first >> monster.second;

    if ((monster.first + direction) % 2 != 0) {
        if (monster.first != m) {
            cout << "NO...";
        } else {
            cout << "YES!";
        }
    } else {
        cout << "NO...";
    }

    return 0;
}
