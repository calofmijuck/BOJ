#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> shares(m + n);
    for (int i = 0; i < n; ++i) {
        cin >> shares[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m + n; ++j) {
            int x;
            cin >> x;
            shares[i] -= x;
            shares[j] += x;
        }
    }

    for (int e : shares) {
        cout << e << ' ';
    }
    return 0;
}
