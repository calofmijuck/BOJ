#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int level;
    cin >> level;

    if (level >= 229) {
        cout << 4;
    } else if (level >= 218) {
        cout << 3;
    } else if (level >= 206) {
        cout << 2;
    } else {
        cout << 1;
    }
    return 0;
}
