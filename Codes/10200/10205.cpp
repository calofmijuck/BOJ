#include <bits/stdc++.h>
using namespace std;

int remaining_heads() {
    int heads = 0;
    string s;

    cin >> heads >> s;
    for (char c : s) {
        if (c == 'b') {
            heads--;
        } else if (c == 'c') {
            heads++;
        }
    }
    return heads;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    for (int i = 1; i <= k; ++i) {
        cout << "Data Set " << i << ":\n";
        cout << remaining_heads() << "\n\n";
    }
    return 0;
}
