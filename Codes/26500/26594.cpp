#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    set<char> alphabets;
    for (char c : s) {
        if (alphabets.find(c) != end(alphabets)) {
            continue;
        }

        alphabets.insert(c);
    }

    cout << s.size() / alphabets.size();
    return 0;
}
