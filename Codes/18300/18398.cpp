#include <bits/stdc++.h>
using namespace std;

void handle_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cout << a + b << ' ' << a * b << '\n';
    }
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
