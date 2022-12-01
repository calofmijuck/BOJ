#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    int count = 0;
    while (t--) {
        string s;
        cin >> s;

        int days = 0;
        for (int i = 2; i < (int) s.size(); ++i) {
            days *= 10;
            days += s[i] - '0';
        }

        if (days <= 90) {
            count++;
        }
    }
    cout << count;
    return 0;
}
