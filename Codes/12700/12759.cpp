#include <bits/stdc++.h>
using namespace std;

char board[4][4];

int fin() {
    if(board[1][1] == board[1][2] && board[1][2] == board[1][3]  || board[1][1] == board[2][1] && board[2][1] == board[3][1]  || board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        if(!board[1][1]) return 0;
        return board[1][1];
    }
    if(board[2][1] == board[2][2] && board[2][2] == board[2][3] || board[1][2] == board[2][2] && board[2][2] == board[3][2] || board[1][3] == board[2][2] && board[2][2] == board[3][1]) {
        if(!board[2][2]) return 0;
        return board[2][2];
    }
    if(board[3][1] == board[3][2] && board[3][2] == board[3][3] || board[1][3] == board[2][3] && board[2][2] == board[3][3]) {
        if(!board[3][3]) return 0;
        return board[3][3];
    }
    return 0;
}

void write(int x, int y, int k) {
    board[x][y] = k;
}

int main() {
    int k, x, y, f = 0, cnt = 0;
    scanf("%d", &k);
    while(f == 0 && (9 - cnt)) {
        scanf("%d %d", &x, &y);
        write(x, y, k);
        cnt++;
        f = fin();
        if(k == 1) k++;
        else k--;
    }
    if(f == 0) puts("0");
    if(f == 1) puts("1");
    if(f == 2) puts("2");
    return 0;
}
