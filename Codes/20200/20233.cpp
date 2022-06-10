#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, x, b, y, t;
    cin >> a >> x >> b >> y >> t;

    int first_cost = a + 21 * max(0, t - 30) * x;
    int second_cost = b + 21 * max(0, t - 45) * y;

    cout << first_cost << ' ' << second_cost;
    return 0;
}
