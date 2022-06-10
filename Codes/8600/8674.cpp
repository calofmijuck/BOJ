#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long width, height;
    cin >> width >> height;

    if (width % 2 == 0 or height % 2 == 0) {
        cout << 0;
    } else {
        cout << min(width, height);
    }

    return 0;
}
