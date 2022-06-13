#include <bits/stdc++.h>
using namespace std;

pair<bool, int> calculate(int n0) {
    int n1 = 3 * n0;
    bool odd = n1 % 2;

    int n2 = odd ? (n1 + 1) / 2 : n1 / 2;
    int n3 = 3 * n2;
    int n4 = n3 / 9;
    return { odd, n4 };
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int input, tc = 1;
    while (true) {
        cin >> input;
        if (input == 0) {
            break;
        }

        auto [odd, result] = calculate(input);
        cout << tc << ". " << (odd ? "odd" : "even") << ' ' << result << '\n';

        tc++;
    }
    return 0;
}
