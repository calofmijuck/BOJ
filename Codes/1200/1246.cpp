#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> price(m);
    for (int i = 0; i < m; ++i) {
        cin >> price[i];
    }

    sort(price.begin(), price.end());

    int sell_price = 0;
    long long total = 0;
    for (int i = m - 1, j = 1; i >= 0 && j <= n; --i, ++j) {
        if (total <= price[i] * j) {
            total = price[i] * j;
            sell_price = price[i];
        }
    }
    cout << sell_price << ' ' << total;
    return 0;
}
