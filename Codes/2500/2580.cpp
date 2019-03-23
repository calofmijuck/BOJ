#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int board[9][9];
vector<pii> vec; // store locations of 0
bool stop;

bool check(int num, int x, int y) {
    int rx = x / 3 * 3, ry = y / 3 * 3;
    for(int i = 0; i < 9; ++i) {
        if(board[x][i] == num || board[i][y] == num) return false;
    }
    for(int i = rx; i < rx + 3; ++i) {
        for(int j = ry; j < ry + 3; ++j) {
            if(board[i][j] == num) return false;
        }
    }
    return true;
}

void printans() {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) printf("%d ", board[i][j]);
        puts("");
    }
    exit(0);
}

bool check() {
    int flag[10];
    memset(flag, 0, sizeof(flag));
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) flag[board[i][j]]++;
        for(int k = 1; k < 10; ++k) {
            if(flag[k] != 1) return false;
        }
        memset(flag, 0, sizeof(flag));
    }
    for(int j = 0; j < 9; ++j) {
        for(int i = 0; i < 9; ++i) flag[board[i][j]]++;
        for(int k = 1; k < 10; ++k) {
            if(flag[k] != 1) return false;
        }
        memset(flag, 0, sizeof(flag));
    }
    for(int x = 0; x < 3; ++x) {
        for(int y = 0; y < 3; ++y) {
            for(int i = 3 * x; i < 3 * x + 3; ++i) {
                for(int j = 3 * y; j < 3 * y + 3; ++j) flag[board[i][j]]++;
            }
            for(int k = 1; k < 10; ++k) {
                if(flag[k] != 1) return false;
            }
            memset(flag, 0, sizeof(flag));
        }
    }
    return true;
}

void solve(int idx) {
    if(idx == (int) vec.size()) printans();
    pii p = vec[idx];
    for(int i = 1; i < 10; ++i) {
        if(check(i, p.first, p.second)) {
            board[p.first][p.second] = i;
            solve(idx + 1);
            board[p.first][p.second] = 0;
        }
    }
}

int main() {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            scanf("%d", &board[i][j]);
            if(board[i][j] == 0) vec.push_back({i, j});
        }
    }
    solve(0);
    return 0;
}
