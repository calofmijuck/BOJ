#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1010

vector<vector<int>> scc_adj;
vector<pair<int, int>> weight;
vector<int> adj[MAX_N];
int visited[MAX_N], scc[MAX_N], cost[MAX_N], indeg[MAX_N];
int mx[MAX_N], mi[MAX_N], dp[MAX_N][MAX_N];
int scc_size, cnt;

stack<int> st;

int dfs(int v) {
    st.push(v);
    visited[v] = ++cnt;
    int parent = visited[v];
    for(int next : adj[v]) {
        if(visited[next] == 0)
            parent = min(parent, dfs(next));
        else if(scc[next] == 0)
            parent = min(parent, visited[next]);
    }
    if(parent == visited[v]) {
        ++scc_size;
        while(true) {
            int t = st.top(); st.pop();
            scc[t] = scc_size;
            ++cost[scc_size];
            if(t == v)
                break;
        }
    }
    return parent;
}

void calculate_max(int v) {
    int ret = mx[v];
    for(int next : scc_adj[v]) {
        mx[v] += mx[next];
        calculate_max(next);
    }
}

int knapsack(int pos, int val) {
    if(pos > weight.size()) return 0;
    int &ret = dp[pos][val];
    if(ret != -1) return ret;
    ret = knapsack(pos + 1, val);
    if(val >= weight[pos].first) {
        for(int i = weight[pos].first; i <= weight[pos].second; ++i) {
            if(i > val) break;
            ret = max(ret, knapsack(pos + 1, val - i) + i);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k, x;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        adj[x].push_back(i);
    }
    for(int i = 1; i <= n; ++i)
        if(!visited[i]) dfs(i);
    
    // build scc graph
    scc_adj.resize(scc_size + 1);
    for(int i = 1; i <= n; ++i) {
        for(int next : adj[i]) {
            if(scc[next] == scc[i])
                continue;
            scc_adj[scc[i]].push_back(scc[next]);
            ++indeg[scc[next]];
        }
    }

    // calculate min/max of people for each v in scc graph
    for(int i = 1; i <= scc_size; ++i)
        mx[i] = mi[i] = cost[i];
    for(int i = 1; i <= scc_size; ++i)
        calculate_max(i);
    
    // create possible weights
    for(int i = 1; i <= scc_size; ++i) {
        if(indeg[i] == 0)
            weight.push_back({mi[i], mx[i]});
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(0, k);
    return 0;
}