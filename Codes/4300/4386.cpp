#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long double ld;
typedef pair<ld, ld> Vertex;
typedef pair<ld, pair<int, int>> Edge;

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
		if (!isSameSet(i, j)) { // if from different set
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ld x, y, sum = 0;
	cin >> n;
	vector<Vertex> vtx;
	vector<Edge> edge;
	for(int i = 0; i < n; ++i) {
		cin >> x >> y;
		vtx.push_back({x, y});
		for(int j = 0; j < i; ++j) {
			long double dist = sqrt((x - vtx[j].first) * (x - vtx[j].first) + (y - vtx[j].second) * (y - vtx[j].second));
			edge.push_back({dist, {i, j}});
		}
	}
	UnionFind uf(n);
	sort(edge.begin(), edge.end());
	for(Edge e : edge) {
		double weight = e.first;
		int src = e.second.first;
		int dst = e.second.second;
		if(!uf.isSameSet(src, dst)) {
			sum += weight;
			uf.unionSet(src, dst);
		}
	}
	cout << sum;
	return 0;
}
