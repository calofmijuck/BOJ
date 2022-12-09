#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;

    int count = 0;
    while (n != 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n >>= 1;
        }

        count++;
    }
    cout << count;
    return 0;
}
