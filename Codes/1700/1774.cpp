#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<double, pii> Edge;

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

inline double dist(pii x, pii y) {
    return (double) (x.first - y.first) * (x.first - y.first) + (double) (x.second - y.second) * (x.second - y.second);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pii> v;
    for(int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    vector<Edge> edges;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            double d = dist(v[i], v[j]);
            edges.push_back({d, {i, j}});
        }
    }
    UnionFind uf(n);
    for(int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        uf.unionSet(x - 1, y - 1);
    }
    sort(edges.begin(), edges.end());
    double sum = 0;
    for(Edge e : edges) {
        int s = e.second.first, t = e.second.second;
        if(!uf.isSameSet(s, t)) {
            sum += sqrt(e.first);
            uf.unionSet(s, t);
        }
    }
    printf("%.2lf", sum);
    return 0;
}