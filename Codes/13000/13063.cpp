#include <bits/stdc++.h>
using namespace std;

int required_lobby(int total, int conservative, int reformist) {
    int minimum = total / 2 + 1;
    int lobby = minimum - conservative;
    if (lobby <= 0) {
        return 0;
    }

    int available = total - reformist - conservative;
    if (available < lobby) {
        return -1;
    }

    return lobby;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int total, conservative, reformist;
    while (true) {
        cin >> total >> conservative >> reformist;
        if (total == 0 && conservative == 0 && reformist == 0) {
            break;
        }

        cout << required_lobby(total, conservative, reformist) << '\n';
    }
    return 0;
}
