#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

vector<int> divisors(int n) {
    vector<int> result;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            result.push_back(i);
        }
    }
    return result;
}

vector<pii> cartesian_product(vector<int>& a, vector<int>& b) {
    vector<pii> product;
    for (int i : a) {
        for (int j : b) {
            product.push_back({i, j});
        }
    }
    sort(begin(product), end(product));
    return product;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int p, q;
    cin >> p >> q;

    vector<int> divisors_p = divisors(p);
    vector<int> divisors_q = divisors(q);
    vector<pii> product = cartesian_product(divisors_p, divisors_q);

    for (pii& p : product) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}
