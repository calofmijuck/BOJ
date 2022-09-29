#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int thickness;
    cin >> thickness;

    string s;
    cin >> s;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (i % thickness == 0) {
            cout << s[i];
        }
    }
    return 0;
}
