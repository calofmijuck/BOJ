#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

bool bulb[10][10], tmp[10][10];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void copy_state() {
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j)
            tmp[i][j] = bulb[i][j];
    }
}

void push(int x, int y) {
    tmp[x][y] ^= 1;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < 10 && 0 <= ny && ny < 10)
            tmp[nx][ny] ^= 1;
    }
}

bool all_off() {
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(tmp[i][j])
                return false;
        }
    }
    return true;
}

int solve() {
    int cnt = 0;
    for(int i = 1; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(tmp[i - 1][j]) {
                push(i, j);
                ++cnt;
            }
        }
    }
    if(all_off())
        return cnt;
    else 
        return INF;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    for(int i = 0; i < 10; ++i) {
        cin >> s;
        for(int j = 0; j < 10; ++j)
            bulb[i][j] = (s[j] == 'O') ? true : false;
    }
    int ans = INF;
    for(int mask = 0; mask < 1024; ++mask) {
        copy_state();
        int e = mask, j = 0, cnt = 0;
        while(e > 0) {
            if(e & 1) {
                push(0, j);
                ++cnt;
            }
            ++j;
            e >>= 1;
        }
        ans = min(ans, cnt + solve());
    }
    cout << ((ans == INF) ? -1 : ans);
    return 0;
}