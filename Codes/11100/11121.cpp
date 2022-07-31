#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string input, output;
        cin >> input >> output;

        cout << (input == output ? "OK" : "ERROR") << '\n';
    }
    return 0;
}
