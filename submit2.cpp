#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> black, white;
int board[10][10], n, ans_black, ans_white;

bool check_bishop(int x, int y) {
    int i = x, j = y;
    while(--i >= 0 && --j >= 0) {
        if(board[i][j] == 2)
            return false;
    }
    i = x, j = y;
    while(++i <= n && ++j <= n) {
        if(board[i][j] == 2)
            return false;
    }
    i = x, j = y;
    while(--i >= 0 && ++j <= n) {
        if(board[i][j] == 2)
            return false;
    }
    i = x, j = y;
    while(++i <= n && --j >= 0) {
        if(board[i][j] == 2)
            return false;
    }
    return true;
}

void black_square(int idx, int cnt) {
    if(idx == (int) black.size()) {
        ans_black = max(ans_black, cnt);
        return;
    }
    pii p = black[idx];
    int x = p.first, y = p.second;
    
    if(check_bishop(x, y)) {
        board[x][y] = 2;
        black_square(idx + 1, cnt + 1);
        board[x][y] = 1;
    }
    black_square(idx + 1, cnt);
}

void white_square(int idx, int cnt) {
    if(idx == (int) white.size()) {
        ans_white = max(ans_white, cnt);
        return;
    }
    pii p = white[idx];
    int x = p.first, y = p.second;
    
    if(check_bishop(x, y)) {
        board[x][y] = 2;
        white_square(idx + 1, cnt + 1);
        board[x][y] = 1;
    }
    white_square(idx + 1, cnt);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> board[i][j];
            if(board[i][j] != 1) continue;
            
            int d = i - j;
            if(d % 2 == 0)
                black.emplace_back(i, j);
            else
                white.emplace_back(i, j);
        }
    }
    black_square(0, 0);
    white_square(0, 0);
    cout << ans_black + ans_white;
}