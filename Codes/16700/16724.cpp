#include <bits/stdc++.h>
using namespace std;

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

	void unionSet(int x, int y) {
        if(rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
	}
};

int n, m, mp[1010][1010];
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

int direction(char c) {
    switch(c) {
        case 'L':
            return 0;
        case 'R':
            return 1;
        case 'U':
            return 2;
        case 'D':
            return 3;
        default:
            return -1;
    }
}

inline int idx(int i, int j) {
    return i * m + j;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        for(int j = 0; j < m; ++j)
            mp[i][j] = direction(str[j]);
    }
    UnionFind uf(n * m);
    int ans = n * m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int dir = mp[i][j];
            int curr_set = uf.findSet(idx(i, j));
            int next_set = uf.findSet(idx(i + dx[dir], j + dy[dir]));
            if(curr_set != next_set) {
                uf.unionSet(curr_set, next_set);
                --ans;
            }
        }
    }
    cout << ans;
    return 0;
}