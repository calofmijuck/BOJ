#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()
#define pb push_back

bool visited[1010][1010][2];
int ans[1010][1010][2];
char mp[1010][1010];
queue<pair<pii, int> > q;
int n, m;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
void bfs(int x, int y) {
    q.push({{0, 0}, 0});
    visited[0][0][0] = true;
    while(!q.empty()) {
        pair<pii, int> curr = q.front();
        q.pop();
        pii loc = curr.first;
        for(int i = 0; i < 4; ++i) {
            int nx = loc.first + dx[i], ny = loc.second + dy[i];
            if(check(nx, ny)) {
                if(visited[nx][ny][curr.second])
                    continue;
                visited[nx][ny][curr.second] = true;
                if(mp[nx][ny] == '0') {
                    q.push({{nx, ny}, curr.second});
                    ans[nx][ny][curr.second] = ans[loc.first][loc.second][curr.second] + 1;
                } else {
                    if(!curr.second) {
                        q.push({{nx, ny}, 1});
                        ans[nx][ny][1] = ans[loc.first][loc.second][0] + 1;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> mp[i];
    }
    ans[0][0][0] = 1;
    bfs(0, 0);
    int ret = 0;
    if(ans[n - 1][m - 1][0] == 0 && ans[n - 1][m - 1][1] == 0)
        ret = - 1;
    else if(ans[n - 1][m - 1][0] == 0)
        ret = ans[n - 1][m - 1][1];
    else if(ans[n - 1][m - 1][1] == 0)
        ret = ans[n - 1][m - 1][0];
    else
        ret = min(ans[n - 1][m - 1][0], ans[n - 1][m - 1][1]);
    cout << ret;
}
