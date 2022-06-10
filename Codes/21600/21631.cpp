#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long white, black;
    cin >> white >> black;

    if (white >= black) {
        cout << black;
    } else if (white < black) {
        cout << white + 1;
    }

    return 0;
}
