#include <bits/stdc++.h>
using namespace std;

void print_figure(int n) {
    string header(n + 2, '@');
    string spaces(n, ' ');

    cout << header << '\n';
    for (int line = 2; line <= n + 1; ++line) {
        cout << '@' << spaces << '@' << '\n';
    }
    cout << header;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    print_figure(n);
    return 0;
}
