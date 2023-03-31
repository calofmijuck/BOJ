#include <bits/stdc++.h>
using namespace std;

int move_x[8] = { -1, -1, 1, 1, -2, -2, 2, 2 };
int move_y[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };

void solve(int tc) {
    cout << "Case " << tc << ": ";

    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;

    for (int j = 0; j < 8; ++j) {
        int next_x = start_x + move_x[j];
        int next_y = start_y + move_y[j];
        if (next_x == end_x && next_y == end_y) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) {
        int board_size;
        cin >> board_size;

        solve(i);
    }
    return 0;
}
