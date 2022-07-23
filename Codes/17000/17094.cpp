#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int two_count = 0, e_count = 0;
    for (char c : s) {
        if (c == '2') {
            two_count++;
        } else {
            e_count++;
        }
    }

    if (two_count > e_count) {
        cout << 2;
    } else if (two_count < e_count) {
        cout << 'e';
    } else {
        cout << "yee";
    }

    return 0;
}
