#include <bits/stdc++.h>
using namespace std;

int board[9][9];

int main() {
    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; ++k) {
        printf("Case %d: ", k + 1);
        bool invalid = false;
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) scanf("%d", &board[i][j]);
        }
        for(int r = 0; r < 9; ++r) {
            int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for(int c = 0; c < 9; ++c) count[board[r][c]]++;
            for(int i = 1; i <= 9; ++i) {
                if(count[i] != 1) invalid = true;
            }
        }
        for(int c = 0; c < 9; ++c) {
            int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for(int r = 0; r < 9; ++r) count[board[r][c]]++;
            for(int i = 1; i <= 9; ++i) {
                if(count[i] != 1) invalid = true;
            }
        }
        for(int x = 0; x < 3; ++x) {
            for(int y = 0; y < 3; ++y) {
                int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                for(int i = 3 * x; i < 3 * x + 3; ++i) {
                    for(int j = 3 * y; j < 3 * y + 3; ++j) count[board[i][j]]++;
                }
                for(int i = 1; i <= 9; ++i) {
                    if(count[i] != 1) invalid = true;
                }
            }
        }
        if(invalid) printf("INCORRECT\n");
        else printf("CORRECT\n");
    }
    return 0;
}
