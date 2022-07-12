#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string line;
    getline(cin, line);

    for (int i = 1; i <= n; ++i) {
        getline(cin, line);
        cout << i << ". " << line << '\n';
    }
    return 0;
}
