#include <bits/stdc++.h>
using namespace std;

int k1, k2, k3, res1, res2;
string o1, o2;

int op(int op1, string o, int op2) {
    char c = o.at(0);
    switch(c) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
    }
}

int main() {
    cin >> k1 >> o1 >> k2 >> o2 >> k3;
    res1 = op(k1, o1, k2);
    res1 = op(res1, o2, k3);
    res2 = op(k2, o2, k3);
    res2 = op(k1, o1, res2);
    printf("%d\n%d", min(res1, res2), max(res1, res2));
    return 0;
}
