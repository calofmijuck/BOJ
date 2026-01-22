#include <bits/stdc++.h>
using namespace std;

int gear_top[4] = { 0, 0, 0, 0 };
string gear[4];

const int mod = 8;

int get_left(int num) {
    int idx = (gear_top[num] + 6) % mod;
    return gear[num][idx];
}

int get_right(int num) {
    int idx = (gear_top[num] + 2) % mod;
    return gear[num][idx];
}

void move_gear(int num, int direction) {
    vector<pair<int, int>> to_move;
    to_move.emplace_back(num, direction);

    // check to the left
    int left_direction = -direction;
    for (int i = num - 1; i >= 0; --i) {
        if (get_right(i) == get_left(i + 1)) {
            break;
        }

        to_move.emplace_back(i, left_direction);
        left_direction = -left_direction;
    }

    // check to the right
    int right_direction = -direction;
    for (int i = num + 1; i <= 3; ++i) {
        if (get_right(i - 1) == get_left(i)) {
            break;
        }

        to_move.emplace_back(i, right_direction);
        right_direction = -right_direction;
    }

    for (auto& [move_num, dir] : to_move) {
        gear_top[move_num] += (dir == 1) ? 7 : 1;
        gear_top[move_num] %= mod;
    }
}

int solve(int moves) {
    int num, direction;
    for (int i = 0; i < moves; ++i) {
        cin >> num >> direction;
        move_gear(num - 1, direction);
    }

    int score = 0;
    for (int i = 0; i < 4; ++i) {
        score += (gear[i][gear_top[i]] == '1') ? (1 << i) : 0;
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 4; ++i) {
        cin >> gear[i];
    }

    int k;
    cin >> k;
    cout << solve(k);
    return 0;
}
