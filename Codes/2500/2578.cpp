#include <iostream>
using namespace std;

bool mark[5][5];

void print() {
    for(int i = 0; i < 5; ++i) {
        for(int j =0 ; j < 5; ++j) {
            cout << mark[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int check() {
    int ret = 0;
    bool c = true;
    for(int i = 0; i < 5; ++i) {
        c = true;
        for(int j = 0; j < 5; ++j) c &= mark[i][j];
        if(c) ret++;
    }
    for(int i = 0; i < 5; ++i) {
        c = true;
        for(int j = 0; j < 5; ++j) c &= mark[j][i];
        if(c) ret++;
    }
    c = true;
    for(int i = 0; i < 5; ++i) c &= mark[i][i];
    if(c) ret++;
    c = true;
    for(int i = 0; i < 5; ++i) c &= mark[i][4 - i];
    if(c) ret++;
    return ret;
}

int main() {
    int board[5][5];
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) cin >> board[i][j];
    }
    for(int i = 0; i < 25; ++i) {
        int k;
        cin >> k;
        for(int x = 0; x < 5; ++x) {
            for(int y = 0; y < 5; ++y) {
                if(board[x][y] == k) mark[x][y] = true;
            }
        }
        if(check() >= 3) {
            cout << i + 1;
            return 0;
        }
    }
}