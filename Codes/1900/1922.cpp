#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> Edge;
typedef long long ll;

class UnionFind {
private:
	vector<int> p, rank;
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
		if(!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, a, b, c;
    vector<Edge> edges;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(n + 1);
    ll res = 0;
    for(Edge e : edges) {
        int weight = e.first;
        int src = e.second.first, dst = e.second.second;
        if(!uf.isSameSet(src, dst)) {
            uf.unionSet(src, dst);
            res += weight;
        }
    }
    cout << res;
}