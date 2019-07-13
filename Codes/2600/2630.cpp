#include <iostream>
using namespace std;

int arr[200][200], blue, white;

void solve(int x, int y, int k) {
    bool check = true;
    int color = arr[x][y];
    for(int i = x; i < x + k; ++i) {
        for(int j = y; j < y + k; ++j) {
            if(color != arr[i][j]) {
                check = false;
                break;
            }
        }
        if(!check) break;
    }
    if(!check) {
        int nlen = k / 2;
        solve(x, y, nlen);
        solve(x + nlen, y, nlen);
        solve(x, y + nlen, nlen);
        solve(x + nlen, y + nlen, nlen);
    } else {
        if(color == 1) blue++;
        else white++;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) cin >> arr[i][j];
    }
    solve(1, 1, n);
    printf("%d\n%d", white, blue);
}
