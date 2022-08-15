#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int total, relations;
    cin >> total >> relations;

    vector<int> friends(total + 1);
    for (int i = 0; i < relations; ++i) {
        int u, v;
        cin >> u >> v;

        friends[u]++;
        friends[v]++;
    }

    for (int i = 0; i < total; ++i) {
        cout << friends[i + 1] << '\n';
    }
    return 0;
}
