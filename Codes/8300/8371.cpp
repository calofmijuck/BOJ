#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string original, changed;
    cin >> n >> original >> changed;

    int diff = 0;
    for (int i = 0; i < n; ++i) {
        diff += (original[i] != changed[i]);
    }
    cout << diff;
    return 0;
}
