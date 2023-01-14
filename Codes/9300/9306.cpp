#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string last, first;
        cin >> last >> first;

        cout << "Case " << i << ": " << first << ", " << last << '\n';
    }
    return 0;
}
