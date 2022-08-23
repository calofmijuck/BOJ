#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n >= 6) {
        cout << "Love is open door";
        return 0;
    }

    int pull;
    cin >> pull;
    while (--n) {
        pull = 1 - pull;
        cout << pull << '\n';
    }
    return 0;
}
