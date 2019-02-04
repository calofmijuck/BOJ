#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32010];
int indeg[32010];
priority_queue<int, vector<int>, greater<int>> heap;

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        indeg[b]++;
    }
    for(int i = 1; i <= n; ++i) {
        if(indeg[i] == 0) heap.push(i);
    }
    while(!heap.empty()) {
        int c = heap.top(); heap.pop();
        printf("%d ", c);
        for(auto v : adj[c]) {
            if(--indeg[v] == 0) heap.push(v);
        }
    }
    return 0;
}
