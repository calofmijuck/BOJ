// Kosaraju's Algorithm for Strongly Connected Components
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10101];
vector<int> adjT[10101];
bool visited[10101];
int finished[10101];
int ftime = 0;

// DFS
void dfs(int v) {
    visited[v] = true;
    for(int next : adj[v]) {
        if(!visited[next]) dfs(next);
    }
    finished[++ftime] = v;
}

// Reverse DFS
void rdfs(int v, vector<int>& cc) {
    cc.push_back(v);
    visited[v] = true;
    for(int next : adjT[v]) {
        if(!visited[next]) rdfs(next, cc);
    }
}

int main() {
    int v, e, s, t;
    scanf("%d %d", &v, &e);
    for(int i = 0; i < e; ++i) {
        scanf("%d %d", &s, &t);
        adj[s].push_back(t);
    }

    // DFS
    for(int i = 1; i <= v; ++i) {
        if(!visited[i]) dfs(i);
    }

    // Clear visited
    memset(visited, 0, sizeof(visited));

    // Transpose the adjacency list
    for(int i = 1; i <= v; ++i ) {
        for(int e : adj[i]) adjT[e].push_back(i);
    }

    vector<vector<int>> scc; // will store SCC

    // Reverse DFS from latest finishing time
    for(int i = v; i >= 1; --i) {
        int curr = finished[i];
        if(!visited[curr]) {
            vector<int> component;
            rdfs(curr, component);
            sort(component.begin(), component.end()); // sort each vertices
            component.push_back(-1);
            scc.push_back(component);
        }
    }

    // sort components
    sort(scc.begin(), scc.end());
    printf("%d\n", (int) scc.size());
    for(vector<int> cc : scc) {
        for(int v : cc) printf("%d ", v);
        puts("");
    }
    return 0;
}
