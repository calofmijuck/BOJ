#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, score, p;
    cin >> n >> score >> p;

    if (n == 0) {
        cout << 1;
        return 0;
    }

    vector<int> ranking(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranking[i];
    }

    if (n == p && score <= ranking.back()) {
        cout << -1;
        return 0;
    }

    int rank = n - 1;
    while (rank >= 0 && ranking[rank] <= score) {
        rank--;
    }

    cout << rank + 2;
    return 0;
}
