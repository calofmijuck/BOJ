#include <bits/stdc++.h>
using namespace std;

int pack[55], ones[55];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> pack[i] >> ones[i];
    }
    sort(pack, pack + m);
    sort(ones, ones + m);
    cout << min({ones[0] * n, (n / 6) * pack[0] + (n % 6) * ones[0], (n + 5) / 6 * pack[0]});
    return 0;
}