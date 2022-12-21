#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, count = 0;
    cin >> n;
    char prev = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s[0] != prev) {
            count++;
        }

        prev = s[0];
    }
    cout << count + 1;
    return 0;
}
