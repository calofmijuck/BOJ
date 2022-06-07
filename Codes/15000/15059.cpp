#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int stock[3];
    for (int i = 0; i < 3; ++i) {
        cin >> stock[i];
    }

    int request[3];
    for (int i = 0; i < 3; ++i) {
        cin >> request[i];
    }

    int shortage = 0;
    for (int i = 0; i < 3; ++i) {
        shortage += max(request[i] - stock[i], 0);
    }

    cout << shortage;
    return 0;
}
