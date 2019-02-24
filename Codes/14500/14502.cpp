#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m, arr[10][10], cpy[10][10];
vector<pii> vec;

void wall(pii &x) {
    cpy[x.first][x.second] = 1;
}

bool chkrange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int i, int j) {
    for(int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if(chkrange(x, y) && !cpy[x][y]) {
            cpy[x][y] = 2;
            dfs(x, y);
        }
    }
}

int process(pii& x, pii& y, pii& z) {
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cpy[i][j] = arr[i][j];
    }
    wall(x); wall(y); wall(z);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(cpy[i][j] == 2) dfs(i, j);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!cpy[i][j]) ret++;
        }
    }
    return ret;
}

int main() {
    int ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0) vec.push_back({i, j});
        }
    }
    int sz = vec.size();
    for(int i = 0; i < sz - 2; ++i) {
        for(int j = i + 1; j < sz - 1; ++j) {
            for(int k = j + 1; k < sz; ++k) {
                pii fi = vec[i], snd = vec[j], thd = vec[k];
                int curr = process(fi, snd, thd);
                ans = max(curr, ans);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
