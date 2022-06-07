#include <bits/stdc++.h>
using namespace std;

int calculate_cost(int n, int pencils, int set_cost) {
    return (int) ceil((double) n / pencils) * set_cost;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int x_set_cost = calculate_cost(n, a, b);
    int y_set_cost = calculate_cost(n, c, d);

    cout << min(x_set_cost, y_set_cost);
    return 0;
}
