#include <bits/stdc++.h>
using namespace std;

int count_pairs(int n, int m) {
    int pairs = 0;
    for (int a = 1; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            int numerator = a * a + b * b + m;
            if (numerator % (a * b) == 0) {
                pairs++;
            }
        }
    }
    return pairs;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        cout << count_pairs(n, m) << '\n';
    }
    return 0;
}
