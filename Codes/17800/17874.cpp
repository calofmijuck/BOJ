#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int side, v, h;
    cin >> side >> v >> h;

    cout << max(side - v, v) * max(side - h, h) * 4;
    return 0;
}
