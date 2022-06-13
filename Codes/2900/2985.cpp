#include <bits/stdc++.h>
using namespace std;

char op[4] = { '+', '-', '*', '/' };

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

bool equal(int a, int b) {
    return a == b;
}

int (*ops[4])(int, int) = { add, subtract, multiply, divide };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 4; ++i) {
        if (equal(a, ops[i](b, c))) {
            cout << a << '=' << b << op[i] << c;
            return 0;
        }

        if (equal(ops[i](a, b), c)) {
            cout << a << op[i] << b << '=' << c;
            return 0;
        }
    }
    return 0;
}
