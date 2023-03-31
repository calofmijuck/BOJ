#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> pick(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pick[x] = i + 1;
    }

    for (int i = 1; i <= n; ++i) {
        cout << pick[i] << '\n';
    }
    return 0;
}
