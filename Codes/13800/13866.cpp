#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int level[4];
    for (int i = 0; i < 4; ++i) {
        cin >> level[i];
    }
    sort(level, level + 4);
    cout << abs(level[3] + level[0] - level[1] - level[2]);
    return 0;
}
