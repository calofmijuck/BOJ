#include <bits/stdc++.h>
using namespace std;

pair<int, int> count_groups(string s) {
    s.push_back('$'); // end of string
    int one_group = 0, zero_group = 0;
    for (int i = 1; i < (int) s.size(); ++i) {
        char prev = s[i - 1], curr = s[i];
        if (curr == prev) {
            continue;
        }

        if (prev == '0') {
            zero_group++;
        } else {
            one_group++;
        }
    }
    return {zero_group, one_group};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;

    auto [zero_group, one_group] = count_groups(s);
    cout << min(zero_group, one_group);
    return 0;
}
