#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, dollars;
    cin >> n >> dollars;

    int sum = 0;
    vector<int> share(n);
    for (int i = 0; i < n; ++i) {
        cin >> share[i];
        sum += share[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << dollars / sum * share[i] << '\n';
    }
    return 0;
}
