#include <bits/stdc++.h>
using namespace std;

void find_winner() {
    double prob[2][3];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> prob[i][j];
        }
    }

    double win1 = 0, win2 = 0;
    for (int i = 0; i < 3; ++i) {
        win1 += prob[0][i] * prob[1][(i + 1) % 3];
        win2 += prob[1][i] * prob[0][(i + 1) % 3];
    }

    if (win1 > win2) {
        cout << "ADAM\n";
    } else if (win1 < win2) {
        cout << "GOSIA\n";
    } else {
        cout << "=\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        find_winner();
    }
    return 0;
}
