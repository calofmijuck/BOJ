#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int row = 1, column = 1;
    int max = 0, curr;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> curr;
            if (curr >= max) {
                max = curr;
                row = i + 1;
                column = j + 1;
            }
        }
    }

    cout << max << '\n' << row << ' ' << column;
    return 0;
}
