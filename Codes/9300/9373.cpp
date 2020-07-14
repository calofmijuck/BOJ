#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, pair<int, int>> Edge;

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

int x[1010], y[1010], r[1010];

inline double dist(int x1, int y1, int x2, int y2) {
    return sqrt((ll) (x1 - x2) * (x1 - x2) + (ll) (y1 - y2) * (y1 - y2));
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int w, n;
        cin >> w >> n;
        for(int i = 0; i < n; ++i)
            cin >> x[i] >> y[i] >> r[i];
        vector<Edge> edge;
        edge.push_back({w, {n, n + 1}});
        for(int i = 0; i < n; ++i) {
            edge.push_back({max(0, x[i] - r[i]), {i, n}});
            edge.push_back({max(0, w - x[i] - r[i]), {i, n + 1}});
            for(int j = 0; j < i; ++j)
                edge.push_back({max(0.0, dist(x[i], y[i], x[j], y[j]) - r[i] - r[j]), {j, i}});
        }
        sort(edge.begin(), edge.end());
        UnionFind uf(n + 2);
        for(int i = 0; i < edge.size(); ++i) {
            Edge e = edge[i];
            double d = e.first;
            int s = e.second.first, t = e.second.second;
            uf.unionSet(s, t);
            if(uf.isSameSet(n, n + 1)) {
                if(d == 0) cout << "0\n";
                else cout << fixed << setprecision(10) << d / 2 << '\n';
                break;
            }
        }
    }
    return 0;
}