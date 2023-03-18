#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int max = 0;
    int thrown_away = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i == 0) {
            max = x;
            continue;
        }

        if (x >= max) {
            thrown_away += x - max;
        } else {
            max = x;
        }
    }
    cout << thrown_away;
    return 0;
}
