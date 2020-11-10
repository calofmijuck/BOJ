#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> Edge;

class UnionFind {
private:
	vi p, rank;
public:
	UnionFind(int n) {
		rank.assign(n, 0); p.resize(n);
		for(int i = 0; i < n; ++i) p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
	}
};

vector<Edge> edges;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    UnionFind uf(n + 1);
    int cost = 0;
    int last_added = 0;
    sort(edges.begin(), edges.end());
    for(Edge e : edges) {
        int weight = e.first;
        int src = e.second.first, dst = e.second.second;
        if(!uf.isSameSet(src, dst)) {
            uf.unionSet(src, dst);
            cost += weight;
            last_added = weight;
        }
    }
    cout << cost - last_added;
    return 0;
}