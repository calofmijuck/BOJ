#include <bits/stdc++.h>
using namespace std;

string CORRECT = "YES";
string INCORRECT = "NO";

string solve() {
    int a, b, result;
    string op, equal_sign;

    cin >> a >> op >> b >> equal_sign >> result;

    bool valid = false;
    if (op[0] == '+') {
        valid = (a + b == result);
    } else {
        valid = (a - b == result);
    }
    return valid ? CORRECT : INCORRECT;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": " << solve() << '\n';
    }
    return 0;
}
