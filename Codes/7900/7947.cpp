#include <bits/stdc++.h>
using namespace std;

int round(int a, int b) {
    return int(round(double(a) / b));
}

void handle_case() {
    int r_sum = 0, g_sum = 0, b_sum = 0;
    for (int i = 0; i < 10; ++i) {
        int r, g, b;
        cin >> r >> g >> b;

        r_sum += r;
        g_sum += g;
        b_sum += b;
    }

    cout << round(r_sum, 10) << ' ' << round(g_sum, 10) << ' ' << round(b_sum, 10) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        handle_case();
    }
    return 0;
}
