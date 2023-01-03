#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> index_map = {
    {'H', 0}, {'I', 1}, {'A', 2}, {'R', 3}, {'C', 4}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int count[5] = { 0 };
    for (char c : s) {
        if (index_map.find(c) == index_map.end()) {
            continue;
        }

        count[index_map[c]]++;
    }

    int answer = 1e9;
    for (int i = 0; i < 5; ++i) {
        answer = min(answer, count[i]);
    }
    cout << answer;
    return 0;
}
