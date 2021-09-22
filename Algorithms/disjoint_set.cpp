#include <bits/stdc++.h>
using namespace std;

class disjoint_set {
private:
    vector<int> p, rank;
public:
    disjoint_set(int n) {
        rank.assign(n, 0);
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int find_set(int i) {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }

    bool is_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }

    void union_set(int i, int j) {
        int x = find_set(i), y = find_set(j);
        if (x == y) return;

        if (rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};
