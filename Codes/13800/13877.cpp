#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> bases = { 8, 10, 16 };

ll as_base(int number, int base) {
    ll value = 0;
    ll exp = 1;
    while (number > 0) {
        int r = number % 10;
        if (r >= base) {
            return 0;
        }

        value += r * exp;
        number /= 10;
        exp *= base;
    }
    return value;
}

void handle_case() {
    int case_num, number;
    cin >> case_num >> number;

    cout << case_num << ' ';
    for (int base : bases) {
        cout << as_base(number, base) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        handle_case();
    }
    return 0;
}
