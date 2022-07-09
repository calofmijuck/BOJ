#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    set<string> strings;

    string line;
    for (int i = 0; i < n; ++i) {
        cin >> line;
        strings.insert(line);
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        cin >> line;
        count += strings.find(line) != strings.end();
    }

    cout << count;
    return 0;
}
