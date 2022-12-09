#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int score[2] = { 0, 0 };
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        if (x == y) {
            score[0] += x;
            score[1] += y;
            continue;
        }

        int winner = (x > y) ? 0 : 1;
        score[winner] += x + y;
    }
    cout << score[0] << ' ' << score[1];
    return 0;
}
