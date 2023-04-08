#include <bits/stdc++.h>
using namespace std;

void print_triangle() {
    int height;
    string letter;
    cin >> height >> letter;

    int diff = letter[0] - 'A';
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            cout << char('A' + diff);
        }
        cout << '\n';

        diff = (diff + 1) % 26;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        print_triangle();
        cout << '\n';
    }
    return 0;
}
