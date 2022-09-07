#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x, y;
    cin >> x >> y;

    cout << int(ceil(double(y) / (y - x)));
    return 0;
}
