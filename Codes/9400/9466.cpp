#include <bits/stdc++.h>
using namespace std;

int cnt;
vector<int> vec;
vector<bool> visited, finished;

void dfs(int v) {
    visited[v] = true;
    int next = vec[v];
    if(!visited[next]) dfs(next);
    else if(!finished[next]) {
        int s = next;
        do {
            cnt++;
            s = vec[s];
        } while(next != s);
    }
    finished[v] = true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cnt = 0;
        vec.clear(); vec.resize(n + 1);
        visited.clear(); visited.resize(n + 1);
        finished.clear(); finished.resize(n + 1);
        for(int i = 1; i <= n; ++i)
            cin >> vec[i];
        for(int i = 1; i <= n; ++i) {
            if(!visited[i]) dfs(i);
        }
        cout << n - cnt << '\n';
    }
    return 0;
}