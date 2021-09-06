#include <bits/stdc++.h>
using namespace std;

char shift(char c, int val) {
    val = val % 26;
    return 'A' + (c - 'A' - val + 26) % 26;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;

    string encoded;
    cin >> encoded;

    string decoded;
    for (int i = 0; i < (int) encoded.size(); ++i) {
        int shift_value = 3 * (i + 1) + k;
        char decoded_character = shift(encoded[i], shift_value);
        decoded.push_back(decoded_character);
    }
    cout << decoded;
    return 0;
}
