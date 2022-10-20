#include <bits/stdc++.h>
using namespace std;

pair<int, int> coefficients[3] = { {30, 40}, {35, 30}, {40, 20} };

int find_min_cost(int call, int data) {
    int min_cost = numeric_limits<int>::max();
    for (int i = 0; i < 3; ++i) {
        min_cost = min(min_cost, coefficients[i].first * call + coefficients[i].second * data);
    }
    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (true) {
        int call, data;
        cin >> call >> data;
        if (call == 0 and data == 0) {
            break;
        }

        cout << find_min_cost(call, data) << "\n";
    }
    return 0;
}
