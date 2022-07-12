#include <bits/stdc++.h>
using namespace std;

int row_number = 'L' - 'A' + 1;
int column_number = 4;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int row, column;
        cin >> row >> column;

        if (row < row_number or column < column_number) {
            cout << -1 << '\n';
        } else {
            cout << (row_number - 1) * column + 4 << '\n';
        }
    }
    return 0;
}
