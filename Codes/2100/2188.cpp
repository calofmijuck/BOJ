#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
vector<bool> visited;
vector<int> match;

bool dfs(int n) {
    if(visited[n]) return false;
    visited[n] = true;
    for(int i = 0; i < arr[n].size(); ++i) {
        int v = arr[n][i] - 1;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = n;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, t, res = 0;
    scanf("%d %d", &n, &m);
    match.resize(m, -1);
    arr.resize(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t);
        arr[i].resize(t);
        for(int j = 0; j < t; ++j)
            scanf("%d", &arr[i][j]);
    }
    for(int i = 0; i < n; ++i) {
        visited.clear();
        visited.resize(m);
        if(dfs(i)) res++;
    }
    printf("%d", res);
    return 0;
}
