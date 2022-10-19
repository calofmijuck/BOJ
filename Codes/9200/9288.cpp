#include <bits/stdc++.h>
using namespace std;

void print_pairs() {
    int sum;
    cin >> sum;
    for (int i = 1; i <= 6; ++i) {
        for (int j = i; j <= 6; ++j) {
            if (i + j == sum) {
                cout << "(" << i << "," << j << ")\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int c = 1; c <= t; ++c) {
        cout << "Case " << c << ":\n";
        print_pairs();
    }
    return 0;
}
