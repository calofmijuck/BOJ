#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long p1, q1, p2, q2;
    cin >> p1 >> q1 >> p2 >> q2;

    cout << (int) ((p1 * p2) % (2 * q1 * q2) == 0);
    return 0;
}
