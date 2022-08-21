#include <bits/stdc++.h>
using namespace std;

int solve(int people, int current, int k) {
    int diff = k - 3;
    current += diff;

    current %= people;
    if (current <= 0) {
        current += people;
    }

    return current;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int people, current, k;
    cin >> people >> current >> k;

    cout << solve(people, current, k);
    return 0;
}
