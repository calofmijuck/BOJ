#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    cout << (int) ((x + y) < z + 0.5);
    return 0;
}
