#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    for (int i = 1; i <= n; ++i) {
        cout << a * n + b * i << ' ';
    }
    return 0;
}
