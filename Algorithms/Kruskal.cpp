// Kruskal's MST algorithm - refer to #1197

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> Edge;

class UnionFind {
private:
	vi p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, e, sum = 0;
	cin >> v >> e;
	int w, s, t;
	vector<Edge> edge;
	UnionFind uf(v);
	for(int i = 0; i < e; ++i) {
		cin >> s >> t >> w;
		edge.push_back({w, {s - 1, t - 1}});
	}
	sort(edge.begin(), edge.end());
	for(Edge curr : edge) {
		int weight = curr.first;
		int src = curr.second.first;
		int dst = curr.second.second;
		if(!uf.isSameSet(src, dst)) {
			sum += weight;
			uf.unionSet(src, dst);
		}
	}
	cout << sum;
	return 0;
}
