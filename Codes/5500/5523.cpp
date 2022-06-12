#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int win_a = 0, win_b = 0;

    int tc;
    cin >> tc;
    while (tc--) {
        int score_a, score_b;
        cin >> score_a >> score_b;
        if (score_a > score_b) {
            win_a++;
        } else if (score_a < score_b) {
            win_b++;
        }
    }

    cout << win_a << ' ' << win_b;
    return 0;
}
