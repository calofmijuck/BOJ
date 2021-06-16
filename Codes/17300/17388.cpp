#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int s, k, h;
    cin >> s >> k >> h;
    int sum = s + k + h;
    if (sum >= 100) {
        cout << "OK";
    } else {
        if (s < k && s < h) {
            cout << "Soongsil";
        } else if (k < s && k < h) {
            cout << "Korea";
        } else {
            cout << "Hanyang";
        }
    }
    return 0;
}
