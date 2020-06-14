#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1010], adjT[1010], mi, mx;
vector<bool> visited;
int fin[1010], group[1010];
int ftime, cnt, size;

void dfs(int v) {
    visited[v] = true;
    for(int next : adj[v])
        if(!visited[next]) dfs(next);
    fin[++ftime] = v;
}

void rdfs(int v) {
    visited[v] = true;
    size++;
    group[v] = cnt;
    for(int next : adjT[v])
        if(!visited[next]) rdfs(next);
}

int main() {
    int n, k, x;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        adj[x].push_back(i);
        adjT[i].push_back(x);
    }
    visited.clear(); visited.resize(n + 1);
    for(int i = 1; i <= n; ++i)
        if(!visited[i]) dfs(i);
    visited.clear(); visited.resize(n + 1);
    for(int i = n; i > 0; --i) {
        int curr = fin[i];
        if(!visited[curr]) {
            size = 0;
            cnt++;
            rdfs(curr);
        }
    }    
    return 0;
}