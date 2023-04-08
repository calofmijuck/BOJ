#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int posts, commands, target;
    cin >> posts >> commands >> target;

    int position = 1, count = (target == 1) ? 1 : 0;
    for (int i = 0; i < commands; ++i) {
        int op;
        cin >> op;

        position += op;
        if (position == posts + 1) {
            position = 1;
        } else if (position == 0) {
            position = posts;
        }

        if (position == target) {
            count++;
        }
    }
    cout << count;
    return 0;
}
