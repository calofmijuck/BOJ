#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int odd = 0, even = 0, x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    cout << int(odd == even + 1 or odd == even);
    return 0;
}
