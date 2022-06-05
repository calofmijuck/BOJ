#include <bits/stdc++.h>
using namespace std;

void print_figure(int n) {
    string fill(n, '@');
    string space(n, ' ');

    for (int i = 0; i < n; ++i) {
        cout << fill << fill << fill << space << fill << '\n';
    }

    for (int i = 0; i < 3 * n; ++i) {
        cout << fill << space << fill << space << fill << '\n';
    }

    for (int i = 0; i < n; ++i) {
        cout << fill << space << fill << fill << fill << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    print_figure(n);
    return 0;
}
