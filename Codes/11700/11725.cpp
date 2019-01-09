#include <bits/stdc++.h>
using namespace std;

int ans[101010] = {0, 1};
vector<int> adj[101010];

void bfs(int v) {
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int i: adj[curr]) {
            if(!ans[i]) {
                ans[i] = curr;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, st, ed;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &st, &ed);
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    bfs(1);
    for(int i = 2; i <= n; ++i) printf("%d\n", ans[i]);
    return 0;
}
