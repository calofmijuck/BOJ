#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Fenwick {
    vector<int> tree;
    Fenwick(int n) : tree(n + 1) {}

    int sum(int pos) {
        ++pos;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    vec.resize(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];
    Fenwick tree(1000001);
    ll ret = 0;
    for(int i = 0; i < vec.size(); ++i) {
        ret += tree.sum(1000000) - tree.sum(vec[i]);
        tree.add(vec[i], 1);
    }
    cout << ret;
}
