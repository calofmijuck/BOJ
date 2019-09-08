#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vector<vi> gph;
vector<pii> edges;
int visited[50010];

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

bool detectCycle(int v) {
    if(visited[v]) {
        if(visited[v] == -1) return true;
        else return false;
    }
    visited[v] = -1;
    for(int next : gph[v]) {
        if(detectCycle(next)) return true;
    }
    visited[v] = 1;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    gph.resize(n + 1);
    UnionFind uf(n + 1);
    for(int i = 0; i < m; ++i) {
        int k, l;
        string s;
        cin >> k >> s >> l;
        if(s[0] == '=') uf.unionSet(k, l);
        else edges.push_back({k, l});
    }
    for(pii edge : edges) {
        int u = uf.findSet(edge.first), v = uf.findSet(edge.second);
        gph[u].push_back(v);
    }
    for(int i = 0; i < n; ++i) {
        if(detectCycle(i)) {
            cout << "inconsistent";
            return 0;
        }
    }
    cout << "consistent";
    return 0;
}