#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char arr[12][7];

list<pii> removeBlocks;
set<pii> blocks;

inline bool checkRange(int x, int y) {
    return 0 <= x && x < 12 && 0 <= y && y < 6;
}

int dfs(pii p, set<pii>& visited) {
    for(int i = 0; i < 4; ++i) {
        int nx = p.first + dx[i], ny = p.second + dy[i];
        if(!checkRange(nx, ny)) continue;
        if(arr[nx][ny] != arr[p.first][p.second]) continue;
        if(visited.find({nx, ny}) != visited.end()) continue;
        visited.insert({nx, ny});
        dfs({nx, ny}, visited);
    }
    return visited.size();
}

void fall() {
    for(pii p : removeBlocks) {
        arr[p.first][p.second] = '.';
        blocks.erase(p);
    }
    int s, b;
    for(int i = 0; i < 6; ++i) {
        s = b = 12;
        while(s >= b && s >= 0 && b >= 0) {
            while(arr[--s][i] != '.' && s > 0);
            b = s;
            while(arr[--b][i] == '.' && b >= 0);
            if(s < b || s < 0 || b < 0) continue;
            blocks.erase({b, i});
            blocks.insert({s, i});
            arr[s][i] = arr[b][i];
            arr[b][i] = '.';
        }
    }
}

int main() {
    for(int i = 0; i < 12; ++i) {
        scanf("%s", &arr[i]);
        for(int j = 0; j < 6; ++j) {
            if(arr[i][j] != '.')
                blocks.insert({i, j});
        }
    }
    int cnt = 0;
    do {
        removeBlocks.clear();
        for(pii p : blocks) {
            if(arr[p.first][p.second] == '.') continue;
            set<pii> visited;
            if(dfs(p, visited) >= 4) {
                for(pii q : visited) {
                    removeBlocks.push_back(q);
                }
            }
        }
        if(!removeBlocks.empty()) {
            cnt++;
            fall();
        }
    } while(!removeBlocks.empty());
    printf("%d", cnt);
    return 0;
}
