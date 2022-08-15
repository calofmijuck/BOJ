#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> sides(3);
    for (int i = 0; i < 3; ++i) {
        cin >> sides[i];
    }

    sort(begin(sides), end(sides));

    if (sides[2] >= sides[0] + sides[1]) {
        sides[2] = sides[0] + sides[1] - 1;
    }

    cout << sides[0] + sides[1] + sides[2];
    return 0;
}
