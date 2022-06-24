#include <bits/stdc++.h>
using namespace std;

vector<int> parse(string& line) {
    vector<int> result;
    int number = 0;
    for (char c : line) {
        if (c == ' ') {
            result.push_back(number);
            number = 0;
            continue;
        }

        number = 10 * number + (c - '0');
    }
    result.push_back(number);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string line;
    while (getline(cin, line)) {
        vector<int> input = parse(line);
        cout << max(input[1] - input[0], input[2] - input[1]) - 1 << '\n';
    }
    return 0;
}
