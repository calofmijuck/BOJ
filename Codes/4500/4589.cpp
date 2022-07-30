#include <bits/stdc++.h>
using namespace std;

const string ordered = "Ordered";
const string unordered = "Unordered";

string is_ordered() {
    int x, y, z;
    cin >> x >> y >> z;
    if ((x >= y and y >= z) or (x <= y and y <= z)) {
        return ordered;
    }

    return unordered;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    cout << "Gnomes:\n";
    while (t--) {
        cout << is_ordered() << '\n';
    }
    return 0;
}
