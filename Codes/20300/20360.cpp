#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int position = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            cout << position << ' ';
        }

        position++;
        n /= 2;
    }
    return 0;
}
