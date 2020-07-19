#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind {
private:
	vi p, rank, sz;
public:
	UnionFind(int n) {
		rank.assign(n, 0); p.resize(n); sz.assign(n, 1);
		for(int i = 0; i < n; ++i) p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	int unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
		if(x != y) {
			if(rank[x] > rank[y]) {
                p[y] = x;
                sz[x] += sz[y];
                return sz[x];
			} else {
				p[x] = y;
                sz[y] += sz[x];
				if(rank[x] == rank[y]) rank[y]++;
                return sz[y];
			}
		}
        return sz[x];
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<string, int> mp;
        UnionFind uf(2 * n + 1);
        int idx = 1;
        for(int i = 0; i < n; ++i) {
            string a, b;
            cin >> a >> b;
            if(mp.count(a) == 0)
                mp[a] = idx++;
            if(mp.count(b) == 0)
                mp[b] = idx++;
            cout << uf.unionSet(mp[a], mp[b]) << '\n';
        }
    }
	return 0;
}