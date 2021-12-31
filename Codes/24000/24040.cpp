#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll r = n % 9;
        if (r == 0 || r == 2 || r == 5 || r == 8) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
    return 0;
}
