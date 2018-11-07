#include <bits/stdc++.h>
using namespace std;

int n, m, start;
queue<int> q;

vector<int> graph[1001];
bitset<1001> visited;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = true;
    for(int v2: graph[v]) {
        if(!visited[v2]) {
            DFS(v2);
        }
    }
}

void BFS(int v) {
    visited[v] = true;
    q.push(v);
    while(!q.empty()) {
        int f = q.front();
        printf("%d ", f);
        q.pop();
        for(int v2: graph[f]) {
            if(!visited[v2]) {
                q.push(v2);
                visited[v2] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &start);
    int v1, v2;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    DFS(start);
    puts("");
    visited.reset();
    BFS(start);
    return 0;
}
