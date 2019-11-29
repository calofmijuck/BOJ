#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[1001];
int visited[1001];
int match[1001];

bool dfs(int v) {
    if(visited[v]) return false;
    visited[v] = true;
    for(int next : adj[v]) {
        if(!match[next] || dfs(match[next])) {
            match[next] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x, k;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        while(x--) {
            cin >> k;
            adj[i].push_back(k);
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 2; ++j) {
            memset(visited, 0, sizeof(visited));
            if(dfs(i)) ret++;
        }
    }
    cout << ret;
    return 0;
}
