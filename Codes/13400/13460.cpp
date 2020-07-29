#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m, ans = 11, dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
string board[11];
pii out;

inline bool chk(pii p) {
    return 0 <= p.first && p.first < n && 0 <= p.second && p.second < m;
}

void solve(pii red, pii blue, int t) {
    if(t > 10) return;
    for(int i = 0; i < 4; ++i) {
        pii rt = red, bt = blue;
        bool moved = false, redOut = false, blueOut = false;
        do {
            moved = false;
            if(!redOut) {
                pii newRed = {rt.first + dx[i], rt.second + dy[i]};
                if(chk(newRed) && board[newRed.first][newRed.second] != '#' && (newRed != bt || blueOut)) {
                    moved = true;
                    rt = newRed;
                }
                if(rt == out) redOut = true;
            }            
            if(!blueOut) {
                pii newBlue = {bt.first + dx[i], bt.second + dy[i]};
                if(chk(newBlue) && board[newBlue.first][newBlue.second] != '#' && (newBlue != rt || redOut)) {
                    moved = true;
                    bt = newBlue;
                }
                if(bt == out) blueOut = true;
            }
        } while(moved);
        if(redOut && !blueOut) ans = min(ans, t);
        else if(!redOut && !blueOut) {
            solve(rt, bt, t + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    pii red, blue;
    for(int i = 0; i < n; ++i) {
        cin >> board[i];
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 'R')
                red = {i, j};
            else if(board[i][j] == 'B')
                blue = {i, j};
            else if(board[i][j] == 'O')
                out = {i, j};
        }
    }
    board[red.first][red.second] = board[blue.first][blue.second] = '.';
    solve(red, blue, 1);
    if(ans == 11) cout << -1;
    else cout << ans;
    return 0;
}