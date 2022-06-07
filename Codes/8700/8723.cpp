#include <bits/stdc++.h>
using namespace std;

bool pythagorean_triple(vector<int>& lengths) {
    return lengths[2] * lengths[2] == lengths[0] * lengths[0] + lengths[1] * lengths[1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> lengths(3);
    for (int i = 0; i < 3; ++i) {
        cin >> lengths[i];
    }

    sort(begin(lengths), end(lengths));

    if (lengths[0] == lengths[1] and lengths[1] == lengths[2]) {
        cout << 2;
    } else if (pythagorean_triple(lengths)) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}
