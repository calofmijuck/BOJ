#include <bits/stdc++.h>
using namespace std;

void handle_case() {
    int a, b, c;
    cin >> a >> b >> c;

    int count = 0;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                if (i % j == j % k and j % k == k % i) {
                    count++;
                }
            }
        }
    }
    cout << count << '\n';
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
