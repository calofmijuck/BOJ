#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool visited[60][60][60];
int ans = 0;
int MAX_N = 0;

void DFS(int x, int y, int z, int cnt, int last) {
    if(cnt == MAX_N && visited[x + 25][y + 25][z + 25]) {
        ans++;
        return;
    }
    if(cnt == MAX_N) return;
    if(visited[x + 25][y + 25][z + 25]) return;
    visited[x + 25][y + 25][z + 25] = true;
    if(cnt < 0 || cnt % 2 == 1) {
        if(last != 2) DFS(x + 1, y, z, cnt + 1, 1);
        if(last != 3) DFS(x, y - 1, z, cnt + 1, 4);
        if(last != 5) DFS(x, y, z - 1, cnt + 1, 6);
    } else {
        if(last != 1) DFS(x - 1, y, z, cnt + 1, 2);
        if(last != 4) DFS(x, y + 1, z, cnt + 1, 3);
        if(last != 6) DFS(x, y, z + 1, cnt + 1, 5);
    }
    visited[x + 25][y + 25][z + 25] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    MAX_N = n;
    DFS(0, 0, 0, -1, -1);
    cout << ans / 3;
    return 0;
}
