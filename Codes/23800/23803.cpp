#include <bits/stdc++.h>
using namespace std;

void print_figure(int n) {
    string long_cell(5 * n, '@');
    string short_cell(n, '@');
    for (int i = 0; i < 4 * n; ++i) {
        cout << short_cell << '\n';
    }

    for (int i = 0; i < n; ++i) {
        cout << long_cell << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    print_figure(n);
    return 0;
}
