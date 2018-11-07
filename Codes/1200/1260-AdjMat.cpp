#include <bits/stdc++.h>
using namespace std;

int n, m, v, from, to;
bool graph[1010][1010], visited[1010];
queue<int> q;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = true;
    for(int i = 1; i <= n; ++i) {
        if(graph[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int v) {
    visited[v] = true;
    q.push(v);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        printf("%d ", curr);
        for(int i = 1; i <= n; ++i) {
            if(graph[curr][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &v);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &from, &to);
        graph[from][to] = true;
        graph[to][from] = true;
    }
    DFS(v);
    puts("");
    memset(visited, 0, sizeof(visited));
    BFS(v);
    return 0;
}
