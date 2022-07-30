#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;

    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int length = (int) s.size();
        cout << (6 <= length and length <= 9 ? "yes" : "no") << '\n';
    }
    return 0;
}
