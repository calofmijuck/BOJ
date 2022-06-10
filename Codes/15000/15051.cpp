#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int worker[3];
    for (int i = 0; i < 3; ++i) {
        cin >> worker[i];
    }

    cout << 2 * min({ worker[1] + 2 * worker[2], worker[0] + worker[2], 2 * worker[0] + worker[1] });
    return 0;
}
