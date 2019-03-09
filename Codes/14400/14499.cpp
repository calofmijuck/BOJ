#include <bits/stdc++.h>
using namespace std;

int arr[22][22], dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, 1, -1, 0, 0};

class Dice {
public:
    int up, down, north, east, south, west;
    Dice() {
        up = down = north = east = south = west = 0;
    }
    void rollN() {
        int tmp = up;
        up = south;
        south = down;
        down = north;
        north = tmp;
    }

    void rollE() {
        int tmp = up;
        up = west;
        west = down;
        down = east;
        east = tmp;
    }

    void rollS() {
        int tmp = north;
        north = down;
        down = south;
        south = up;
        up = tmp;
    }

    void rollW() {
        int tmp = up;
        up = east;
        east = down;
        down = west;
        west = tmp;
    }
};

int main() {
    int n, m, x, y, k, cmd;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) scanf("%d", &arr[i][j]);
    }
    Dice die;
    for(int i = 0; i < k; ++i) {
        scanf("%d", &cmd);
        int nx = x + dx[cmd], ny = y + dy[cmd];
        if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
        x = nx, y = ny;
        switch(cmd) {
            case 1:
                die.rollE();
                break;
            case 2:
                die.rollW();
                break;
            case 3:
                die.rollN();
                break;
            case 4:
                die.rollS();
                break;
            default:
                break;
        }
        if(arr[x][y] == 0) arr[x][y] = die.down;
        else {
            die.down = arr[x][y];
            arr[x][y] = 0;
        }
        printf("%d\n", die.up);
    }
    return 0;
}
