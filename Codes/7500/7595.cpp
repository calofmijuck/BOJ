#include <bits/stdc++.h>
using namespace std;

void print_triangle(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << '*';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        print_triangle(n);
    }
    return 0;
}
