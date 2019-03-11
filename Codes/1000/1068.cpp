#include <bits/stdc++.h>
using namespace std;

int n, v, st;
vector<int> adj[51];

int bfs(int x) {
    int ret = 0;
    queue<int> q;
    if(x == v) return ret;
    q.push(x);
    while(!q.empty()) {
        int curr = q.front(), cnt = 0;
        q.pop();
        for(int next : adj[curr]) {
            if(next != v) {
                q.push(next);
                cnt++;
            }
        }
        if(cnt == 0) ret++;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v);
        if(v == -1) {
            st = i;
            continue;
        }
        adj[v].push_back(i);
    }
    scanf("%d", &v);
    adj[v].clear();
    printf("%d", bfs(st));
    return 0;
}
