#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAX_N 200005
#define INF 0x3f3f3f3f

vector<pii> adj[MAX_N];
map<int, int> mp;
int n, k, ans = INF, sz[MAX_N];
bool visited[MAX_N];

int get_size(int v, int parent) {
    sz[v] = 1;
    for(auto [next, cost] : adj[v]) {
        if(next == parent || visited[next])
            continue;
        sz[v] += get_size(next, v);
    }
    return sz[v];
}

int find_centroid(int v, int parent, int cap) {
    for(auto [next, cost] : adj[v]) {
        if(next == parent || visited[next])
            continue;
        if(sz[next] > cap)
            return find_centroid(next, v, cap);
    }
    return v;
}

void compute(int v, int parent, int cost, int depth) {
    if(cost > k) 
        return;
    auto it = mp.find(k - cost);
    if(it != mp.end())
        ans = min(ans, it -> second + depth);
    for(auto [next, next_cost] : adj[v]) {
        if(next == parent || visited[next])
            continue;
        else
            compute(next, v, cost + next_cost, depth + 1);
    }
}

void update(int v, int parent, int cost, int depth) {
    if(cost > k)
        return;
    auto it = mp.find(cost);
    if(it != mp.end())
        it -> second = min(it -> second, depth);
    else
        mp[cost] = depth;
    for(auto [next, next_cost] : adj[v]) {
        if(next == parent || visited[next])
            continue;
        update(next, v, cost + next_cost, depth + 1);
    }
}

void solve(int v) {
    int cap = get_size(v, -1) / 2;
    int centroid = find_centroid(v, -1, cap);
    visited[centroid] = true;

    mp.clear(); mp[0] = 0;
    for(auto [next, cost] : adj[centroid]) {
        if(!visited[next]) {
            compute(next, centroid, cost, 1);
            update(next, centroid, cost, 1);
        }
    }
    for(auto [next, cost] : adj[centroid]) {
        if(!visited[next])
            solve(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }
    solve(1);
    if(ans == INF)
        cout << -1;
    else
        cout << ans;
    return 0;
}