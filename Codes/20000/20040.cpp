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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, turns;
    cin >> n >> turns;

    disjoint_set ds(n);
    for (int i = 0; i < turns; ++i) {
        int left, right;
        cin >> left >> right;
        if (ds.is_same_set(left, right)) {
            cout << i + 1;
            return 0;
        } else {
            ds.union_set(left, right);
        }
    }
    cout << 0;
    return 0;
}
