#include <bits/stdc++.h>
using namespace std;

int unused_character_sum(string& s) {
    vector<bool> used(26, false);
    for (char c : s) {
        used[c - 'A'] = true;
    }

    int unused_sum = 0;
    for (int i = 0; i < (int) used.size(); ++i) {
        if (used[i]) {
            continue;
        }

        unused_sum += int('A' + i);
    }
    return unused_sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        cout << unused_character_sum(s) << '\n';
    }
    return 0;
}
