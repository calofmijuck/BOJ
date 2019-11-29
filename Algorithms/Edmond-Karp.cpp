// Calculates Maximum Flow BOJ#17412
#include <bits/stdc++.h>
using namespace std;

#define MAX_V 440

const int INF = 987654321;
int v;

struct Edge {
    int to, cap, f;
    Edge* rev;
    Edge(int t, int c) : to(t), cap(c), f(0), rev(nullptr) {}
    int resCap() const { return cap - f; }
    void push(int x) {
        f += x;
        rev -> f -= x;
    }
};

vector<Edge*> adj[MAX_V];

void addEdge(int u, int v, int cap) {
    Edge* uv = new Edge(v, cap);
    Edge* vu = new Edge(u, 0);
    uv -> rev = vu;
    vu -> rev = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

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
    for(int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b, 1);
    }
    cout << networkFlow(1, 2);
}