#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int candies[3];
    for (int i = 0; i < 3; ++i) {
        cin >> candies[i];
    }

    int maximum = max({ candies[0], candies[1], candies[2] });

    int additional = 0;
    for (int i = 0; i < 3; ++i) {
        additional += maximum - candies[i];
    }

    cout << additional;
    return 0;
}
