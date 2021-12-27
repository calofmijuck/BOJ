#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> triple;

#define MAX_N 200

bool state[MAX_N + 1][MAX_N + 1][MAX_N + 1];
int a, b, c;
triple max_volume;

void bfs() {
    queue<triple> q;
    state[0][0][c] = true;
    q.push({0, 0, c});
    while (!q.empty()) {
        int left, mid, right;
        tie(left, mid, right) = q.front();
        q.pop();
        int n_left, n_mid, n_right, move;

        // 1 -> 2
        move = min(b - mid, left);
        n_mid = mid + move;
        n_left = left - move;
        if (!state[n_left][n_mid][right]) {
            state[n_left][n_mid][right] = true;
            q.push({n_left, n_mid, right});
        }

        // 1 -> 3
        move = min(c - right, left);
        n_right = right + move;
        n_left = left - move;
        if (!state[n_left][mid][n_right]) {
            state[n_left][mid][n_right] = true;
            q.push({n_left, mid, n_right});
        }

        // 2 -> 1
        move = min(a - left, mid);
        n_left = left + move;
        n_mid = mid - move;
        if (!state[n_left][n_mid][right]) {
            state[n_left][n_mid][right] = true;
            q.push({n_left, n_mid, right});
        }

        // 2 -> 3
        move = min(c - right, mid);
        n_right = right + move;
        n_mid = mid - move;
        if (!state[left][n_mid][n_right]) {
            state[left][n_mid][n_right] = true;
            q.push({left, n_mid, n_right});
        }

        // 3 -> 1
        move = min(a - left, right);
        n_left = left + move;
        n_right = right - move;
        if (!state[n_left][mid][n_right]) {
            state[n_left][mid][n_right] = true;
            q.push({n_left, mid, n_right});
        }

        // 3 -> 2
        move = min(b - mid, right);
        n_mid = mid + move;
        n_right = right - move;
        if (!state[left][n_mid][n_right]) {
            state[left][n_mid][n_right] = true;
            q.push({left, n_mid, n_right});
        }
    }
}

set<int> find_possible_states() {
    bfs();

    set<int> possible_states;
    for (int j = 0; j <= b; ++j) {
        for (int k = 0; k <= c; ++k) {
            if (state[0][j][k]) {
                possible_states.insert(k);
            }
        }
    }
    return possible_states;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;

    max_volume = {a, b, c};

    set<int> possible_states = find_possible_states();
    for (int e : possible_states) {
        cout << e << ' ';
    }
    return 0;
}
