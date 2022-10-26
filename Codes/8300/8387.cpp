#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string original, changed;
    cin >> n >> original >> changed;

    int correct = 0;
    for (int i = 0; i < n; ++i) {
        correct += (original[i] == changed[i]);
    }
    cout << correct;
    return 0;
}
