#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> weight(3);
    for (int i = 0; i < 3; ++i) {
        cin >> weight[i];
    }

    sort(begin(weight), end(weight));
    cout << weight[1];
    return 0;
}
