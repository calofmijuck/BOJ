#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int money;
    int n;
    cin >> money >> n;

    for (int i = 0; i < n - 1; ++i) {
        cout << i + 1 << '\n';
        money -= i + 1;
    }
    cout << money;
    return 0;
}
