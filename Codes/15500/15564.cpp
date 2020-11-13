#include <bits/stdc++.h>
using namespace std;

#define MAX 0x3f3f3f3f
#define MAX_N 100010

int parent[22][MAX_N], depth[MAX_N], sz[MAX_N], tree[MAX_N];
bool visited[MAX_N], color[MAX_N];
// black == false, white == true
vector<int> adj[MAX_N];
multiset<int> dist[MAX_N];

// dfs with depth
void dfs(int v, int d) {
    visited[v] = true;
    depth[v] = d;
    for(int next : adj[v]) {
        if(visited[next])
            continue;
        parent[0][next] = v;
        dfs(next, d + 1);
    }
}

// LCA preprocess
void preprocess(int n) {
    parent[0][1] = 1;
    for(int j = 1; j < 22; ++j) {
        for(int i = 1; i <= n; ++i)
            parent[j][i] = parent[j - 1][parent[j - 1][i]];
    }
}

int get_size(int v, int parent) {
    sz[v] = 1;
    for(int next : adj[v]) {
        if(next == parent || visited[next])
            continue;
        sz[v] += get_size(next, v);
    }
    return sz[v];
}

int find_centroid(int v, int parent, int lim) {
    for(int next : adj[v]) {
        if(next == parent || visited[next])
            continue;
        if(sz[next] > lim)
            return find_centroid(next, v, lim);
    }
    return v;
}

// centroid tree
void centroid_tree(int v, int parent = -1) {
    int lim = get_size(v, parent) / 2;
    int centroid = find_centroid(v, parent, lim);
    visited[centroid] = true;

    if(parent == -1)
        tree[centroid] = centroid;
    else
        tree[centroid] = parent;

    for(int next : adj[centroid]) {
        if(!visited[next])
            centroid_tree(next, centroid);
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v])
        swap(u, v);
    int d = depth[u] - depth[v];
    int j = 0;
    while(d > 0) {
        if(d & 1)
            u = parent[j][u];
        ++j;
        d >>= 1;
    }
    if(u == v)
        return u;
    while(parent[0][u] != parent[0][v]) {
        int j = 0;
        while(parent[j][u] != parent[j][v])
            ++j;
        --j;
        u = parent[j][u];
        v = parent[j][v];
    }
    return parent[0][u];
}

int calculate_distance(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void update(int v) {
    color[v] ^= 1;
    int curr = v;
    while(true) {
        int d = calculate_distance(curr, v);
        if(color[v])
            dist[curr].insert(d);
        else
            dist[curr].erase(dist[curr].find(d));
        if(curr == tree[curr])
            break;
        curr = tree[curr];
    }
}

int query(int v) {
    int curr = v;
    int ans = MAX;
    while(true) {
        int d = calculate_distance(curr, v);
        if(!dist[curr].empty())
            ans = min(ans, d + *dist[curr].begin());
        if(curr == tree[curr])
            break;
        curr = tree[curr];
    }
    if(ans >= MAX)
        return -1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1, 0);
    preprocess(n);
    memset(visited, false, sizeof(visited));
    centroid_tree(1);

    // query
    while(q--) {
        int op, x;
        cin >> op >> x;
        if(op == 1)
            update(x);
        else
            cout << query(x) << '\n';
    }
    return 0;
}