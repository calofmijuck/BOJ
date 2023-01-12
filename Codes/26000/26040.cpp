#include <bits/stdc++.h>
using namespace std;

void to_lowercase(string& s, unordered_set<char>& change) {
    for (int i = 0; i < (int) s.size(); ++i) {
        char c = s[i];
        if ('a' <= c && c <= 'z') {
            continue;
        }

        if (change.find(c) == end(change)) {
            continue;
        }

        s[i] = (c - 'A') + 'a';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    unordered_set<char> change;
    string t;
    while (cin >> t) {
        change.insert(t[0]);
    }

    to_lowercase(s, change);
    cout << s;
    return 0;
}
