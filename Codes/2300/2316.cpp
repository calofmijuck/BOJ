#include <bits/stdc++.h>
using namespace std;

#define MAX_V 840

const int INF = 987654321;
int v;

struct Edge {
    int t, cap, f;
    Edge* rev;
    Edge(int t, int c) : t(t), cap(c), f(0), rev(nullptr) {}
    int resCap() const { return cap - f; }
    void push(int x) {
        f += x;
        rev -> f -= x;
    }
};

vector<Edge*> adj[MAX_V];

int networkFlow(int src, int sink) {
    int total = 0;
    while(true) {
        vector<int> parent(MAX_V, -1);
        Edge* path[MAX_V] = {0};
        queue<int> q;
        parent[src] = src;
        q.push(src);
        while(!q.empty() && parent[sink] == -1) {
            int curr = q.front(); q.pop();
            for(Edge* e : adj[curr]) {
                int next = e -> t;
                if(e -> resCap() > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = curr;
                    path[next] = e;
                    if(next == sink) break;
                }
            }
        }
        if(parent[sink] == -1) break;
        int amount = INF;
        for(int p = sink; p != src; p = parent[p])
            amount = min(path[p] -> resCap(), amount);
        for(int p = sink; p != src; p = parent[p])
            path[p] -> push(amount);
        total += amount;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int p;
    cin >> v >> p;
    for(int i = 0; i < v; ++i) {
        int s = 2 * i, t = 2 * i + 1;
        Edge* st = new Edge(t, 1);
        Edge* ts = new Edge(s, 0);
        st -> rev = ts;
        ts -> rev = st;
        adj[s].push_back(st);
        adj[t].push_back(ts);
    }
    for(int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        Edge *uv, *vu;
        uv = new Edge(2 * b, 1);
        vu = new Edge(2 * a + 1, 0);
        uv -> rev = vu;
        vu -> rev = uv;
        adj[2 * a + 1].push_back(uv);
        adj[2 * b].push_back(vu);
        uv = new Edge(2 * a, 1);
        vu = new Edge(2 * b + 1, 0);
        uv -> rev = vu;
        vu -> rev = uv;
        adj[2 * b + 1].push_back(uv);
        adj[2 * a].push_back(vu);
    }
    cout << networkFlow(1, 2);
}