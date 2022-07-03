#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int people, share;
    while (cin >> people) {
        cin >> share;

        cout << int(floor(double(share) / (people + 1))) << '\n';
    }
    return 0;
}
