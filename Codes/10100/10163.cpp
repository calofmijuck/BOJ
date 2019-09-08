#include <bits/stdc++.h>
using namespace std;

int board[150][150];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int k = 0; k < n; ++k) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        for(int i = x; i < x + w; ++i) {
            for(int j = y; j < y + h; ++j) board[i][j] = k + 1;
        }
    }
    for(int k = 1; k <= n; ++k) {
        int area = 0;
        for(int i = 0; i < 101; ++i) {
            for(int j = 0; j < 101; ++j) {
                if(board[i][j] == k) area++;
            }
        }
        cout << area << '\n';
    }

}