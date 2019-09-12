#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, adjT, scc;
vector<bool> visited;
vector<int> fin, group;
int ftime, cnt;

void dfs(int v) {
    visited[v] = true;
    for(int next : adj[v])
        if(!visited[next]) dfs(next);
    fin[++ftime] = v;
}

void rdfs(int v, vector<int>& vec) {
    visited[v] = true;
    vec.push_back(v);
    group[v] = cnt;
    for(int next : adjT[v])
        if(!visited[next]) rdfs(next, vec);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, a, b;
        cin >> n >> m;
        adj.clear(); adj.resize(n + 1);
        adjT.clear(); adjT.resize(n + 1);
        visited.clear(); visited.resize(n + 1);
        fin.clear(); fin.resize(n + 1);
        group.clear(); group.resize(n + 1);
        ftime = cnt = 0;
        for(int i = 0; i < m; ++i) {
            cin >> a >> b;
            adj[a].push_back(b);
            adjT[b].push_back(a);
        }
        for(int i = 0; i < n; ++i)
            if(!visited[i]) dfs(i);
        visited.clear(); visited.resize(n + 1);
        scc.clear();
        for(int i = n; i > 0; --i) {
            int curr = fin[i];
            vector<int> vec;
            if(!visited[curr]) {
                rdfs(curr, vec);
                cnt++;
            }
            scc.push_back(vec);
        }
        vector<int> indeg(cnt, 0);
        for(int i = 0; i < n; ++i) {
            for(int v : adj[i]) {
                if(group[i] == group[v]) continue;
                indeg[group[v]]++;
            }
        }
        int ans_scc, ans = 0;
        for(int i = 0; i < cnt; ++i) {
            if(indeg[i] == 0) {
                ans++;
                ans_scc = i;
            }
        }
        if(ans != 1) cout << "Confused\n";
        else {
            vector<int> s = scc[ans_scc];
            sort(s.begin(), s.end());
            for(int v : s) cout << v << '\n';
        }
        cout << '\n';
    }
    return 0;
}

