#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14159265358;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long a;
    cin >> a;

    cout.precision(10);
    cout << fixed << sqrt((long double) a / PI) * 2 * PI;
    return 0;
}
