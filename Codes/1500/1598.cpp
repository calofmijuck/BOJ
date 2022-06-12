#include <bits/stdc++.h>
using namespace std;

pair<int, int> convert(int n) {
    n--;
    return { n / 4, n % 4 };
}

int right_distance(int a, int b) {
    auto [column1, row1] = convert(a);
    auto [column2, row2] = convert(b);
    return abs(column1 - column2) + abs(row1 - row2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    cout << right_distance(a, b);
    return 0;
}
