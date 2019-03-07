#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int r, c, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char field[255][255];
bool visited[255][255];

bool check(int x, int y) {
    return 0 <= x && x <= r && 0 <= y && y <= c;
}

pii bfs(int a, int b) {
    queue<pii> q;
    visited[a][b] = true;
    q.push({a, b});
    int sheep = 0, wolf = 0;
    while(!q.empty()) {
        pii curr = q.front();
        q.pop();
        char c = field[curr.first][curr.second];
        if(c == 'v') wolf++;
        else if(c == 'o') sheep++;
        for(int i = 0; i < 4; ++i) {
            pii next = {curr.first + dx[i], curr.second + dy[i]};
            if(!check(next.first, next.second) || field[next.first][next.second] == '#') continue;
            if(!visited[next.first][next.second]) {
                q.push(next);
                visited[next.first][next.second] = true;
            }
        }
    }
    return {sheep, wolf};
}

int main() {
    pii ans = {0, 0};
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; ++i) scanf("%s", field[i]);
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(!visited[i][j] && field[i][j] != '#') {
                pii x = bfs(i, j);
                if(x.first > x.second) ans.first += x.first;
                else ans.second += x.second;
            }
        }
    }
    printf("%d %d", ans.first, ans.second);
    return 0;
}
