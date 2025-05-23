#include <bits/stdc++.h>
using namespace std;

vector<int> preprocess(string& s) {
    vector<int> count(26);
    for (char c : s) {
        int idx = c - 'a';
        count[idx]++;
    }

    return count;
}

void solve() {
    string s;
    cin >> s;

    auto count = preprocess(s);

    string answer;
    for (int i = 0; i < int(s.size()); ++i) {
        int max_idx = max_element(begin(count), end(count)) - begin(count);
        int max_count = count[max_idx];

        int remaining = s.size() - i - max_count;
        if (max_count > remaining + 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }

        if (max_count == remaining + 1) {
            answer.push_back('a' + max_idx);
            count[max_idx]--;
            continue;
        }

        for (int j = 0; j < 26; ++j) {
            if (count[j] == 0) {
                continue;
            }

            char next_char = 'a' + j;
            if (i > 0 && answer.back() == next_char) {
                continue;
            }

            count[j]--;
            answer.push_back(next_char);
            break;
        }
    }

    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
