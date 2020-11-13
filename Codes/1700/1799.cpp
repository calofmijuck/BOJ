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

int solve(int idx, int cnt, vector<pii> list) {
    if(idx == (int) list.size())
        return cnt;

    int ret = 0;
    auto& [x, y] = list[idx];
    if(check_bishop(x, y)) {
        board[x][y] = 2;
        ret = max(ret, solve(idx + 1, cnt + 1, list));
        board[x][y] = 1;
    }
    ret = max(ret, solve(idx + 1, cnt, list));
    return ret;
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
    cout << solve(0, 0, black) + solve(0, 0, white);
}