#include <bits/stdc++.h>
using namespace std;

bool is_numeric(string& s) {
    for (char c : s) {
        if (c < '0' or c > '9') {
            return false;
        }
    }
    return true;
}

int to_int(string& s) {
    int result = 0;
    for (char c : s) {
        result *= 10;
        result += c - '0';
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string op1, op2;
    cin >> op1 >> op2;
    if (is_numeric(op1) && is_numeric(op2)) {
        cout << to_int(op1) - to_int(op2);
    } else {
        cout << "NaN";
    }
    return 0;
}
