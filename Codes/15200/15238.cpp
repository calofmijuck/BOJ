#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int count[26] = { 0 };
    for (char c : s) {
        count[c - 'a'] ++;
    }

    int max_index = 0, max_value = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > max_value) {
            max_value = count[i];
            max_index = i;
        }
    }

    cout << char('a' + max_index) << ' ' << max_value;
    return 0;
}
