#include <bits/stdc++.h>
using namespace std;

int board[5][5], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bitset<1000000> found;

void search(int x, int y, int cnt, int num) {
    if(cnt == 6) {
        found[num] = true;
        return;
    }
    int newnum = 10 * num + board[x][y];
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < 5 && 0 <= ny && ny < 5) search(nx, ny, cnt + 1, newnum);
    }
}

int main() {
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) cin >> board[i][j];
    }
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            search(i, j, 0, 0);
        }
    }
    cout << found.count();
}