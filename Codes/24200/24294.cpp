#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;

    int tiles = 2 * (w1 + h1 + w2 + h2 - min(w1, w2)) - 1 + 5;
    cout << tiles;
    return 0;
}
