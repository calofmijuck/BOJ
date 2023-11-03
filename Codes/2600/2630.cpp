#include <bits/stdc++.h>
using namespace std;

#define MAX_N 128

typedef pair<int, int> pii;

int board[MAX_N][MAX_N];

pii divide_and_conquer(int x, int y, int n) {
    if (n == 1) {
        if (board[x][y] == 1) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }

    int half = n / 2;
    pii top_left = divide_and_conquer(x, y, half);
    pii top_right = divide_and_conquer(x, y + half, half);
    pii bottom_left = divide_and_conquer(x + half, y, half);
    pii bottom_right = divide_and_conquer(x + half, y + half, half);

    // all blue
    if (top_left.first == 0 && top_right.first == 0 && bottom_left.first == 0 && bottom_right.first == 0) {
        return {0, 1};
    }

    // all white
    if (top_left.second == 0 && top_right.second == 0 && bottom_left.second == 0 && bottom_right.second == 0) {
        return {1, 0};
    }

    return {
        top_left.first + top_right.first + bottom_left.first + bottom_right.first,
        top_left.second + top_right.second + bottom_left.second + bottom_right.second
    };
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    pii papers = divide_and_conquer(0, 0, n);
    cout << papers.first << '\n' << papers.second;
    return 0;
}
