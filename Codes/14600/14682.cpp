#include <bits/stdc++.h>
using namespace std;

int multiplier(int shift) {
    int result = 0, power = 1;
    for (int i = 0; i <= shift; ++i) {
        result += power;
        power *= 10;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, shift;
    cin >> n >> shift;

    cout << n * multiplier(shift);
    return 0;
}
