#include <bits/stdc++.h>
using namespace std;

int calculate(int a, int c, int prime, int x) {
    return (a * x + c) % prime;
}

bool validate(int a, int c, int prime, vector<int>& values) {
    for (int i = 0; i < 2; ++i) {
        int next = calculate(a, c, prime, values[i]);
        if (next != values[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int prime;
    cin >> prime;

    vector<int> values(3);
    for (int i = 0; i < 3; ++i) {
        cin >> values[i];
    }

    for (int a = 0; a < prime; ++a) {
        for (int c = 0; c < prime; ++c) {
            bool found = validate(a, c, prime, values);
            if (found) {
                cout << a << ' ' << c;
                return 0;
            }
        }
    }
    return 0;
}
