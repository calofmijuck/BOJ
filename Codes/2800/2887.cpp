#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, pii> Edge;

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

void preprocess(vector<pii>& v, vector<Edge>& edges) {
	sort(v.begin(), v.end());
	for(int i = 1; i < v.size(); ++i) {
		ll w = abs(v[i].first - v[i - 1].first);
		int s = v[i].second;
		int t = v[i - 1].second;
		edges.push_back({w, {s, t}});
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pii> x, y, z;
	x.resize(n); y.resize(n); z.resize(n);
	for(int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		x[i] = {a, i};
		y[i] = {b, i};
		z[i] = {c, i};
	}
	vector<Edge> edges;
	preprocess(x, edges);
	preprocess(y, edges);
	preprocess(z, edges);
	sort(edges.begin(), edges.end());
	UnionFind uf(n);
	ll ans = 0;
	for(Edge e : edges) {
		ll w = e.first;
		int s = e.second.first, t = e.second.second;
		if(!uf.isSameSet(s, t)) {
			uf.unionSet(s, t);
			ans += w;
		}
	}
	cout << ans;
	return 0;
}