#include <iostream>
using namespace std;
typedef long long ll;

int n;
char board[100][100];

int check() {
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        char prev = board[i][0];
        int cnt = 1;
        for(int j = 1; j < n; ++j) {
            if(prev == board[i][j]) {
                cnt++;
                ret = max(cnt, ret);
            } else {
                ret = max(cnt, ret);
                cnt = 1;
            }
            prev = board[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        char prev = board[0][i];
        int cnt = 1;
        for(int j = 1; j < n; ++j) {
            if(prev == board[j][i]) {
                cnt++;
                ret = max(cnt, ret);
            } else {
                ret = max(cnt, ret);
                cnt = 1;
            }
            prev = board[j][i];
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%s", board[i]);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            if(board[i][j] != board[i][j + 1]) {
                swap(board[i][j], board[i][j + 1]);
                ans = max(check(), ans);
                swap(board[i][j], board[i][j + 1]);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            if(board[j][i] != board[j + 1][i]) {
                swap(board[j][i], board[j + 1][i]);
                ans = max(check(), ans);
                swap(board[j][i], board[j + 1][i]);
            }
        }
    }
    printf("%d", ans);
}
