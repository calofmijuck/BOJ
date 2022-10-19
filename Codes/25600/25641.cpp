#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string s;

    cin >> n >> s;

    int diff = 0, max_length = 0;
    for (int i = n - 1; i >= 0; --i) {
        char c = s[i];
        if (c == 't') {
            diff++;
        } else {
            diff--;
        }

        if (diff == 0) {
            max_length = max(max_length, n - i);
        }
    }
    cout << s.substr(n - max_length, max_length);
    return 0;
}
