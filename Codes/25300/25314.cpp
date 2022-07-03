#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int bytes;
    cin >> bytes;

    int long_count = bytes / 4;
    for (int i = 0; i < long_count; ++i) {
        cout << "long ";
    }
    cout << "int";
    return 0;
}
