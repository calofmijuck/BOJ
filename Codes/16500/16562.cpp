#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

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

int cost[10010], val[10010];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> cost[i];
    int u, v;
	UnionFind uf(n + 1);
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        uf.unionSet(u, v);
    }
    for(int i = 1; i <= n; ++i) {
        int s = uf.findSet(i);
        if(val[s] == 0)
            val[s] = cost[i];
        else
            val[s] = min(val[s], cost[i]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += val[i];
    if(ans > k)
        cout << "Oh no";
    else
        cout << ans;
	return 0;
}
