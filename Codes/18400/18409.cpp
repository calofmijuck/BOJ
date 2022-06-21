#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int vowels = 0;
    for (char c : s) {
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
            vowels++;
        }
    }

    cout << vowels;
    return 0;
}
