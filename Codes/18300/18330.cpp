#include <bits/stdc++.h>
using namespace std;

const int quota_price = 1500;
const int extra_price = 3000;

int petrol_cost(int quota, int value) {
    if (value <= quota) {
        return value * quota_price;
    }

    return quota * quota_price + (value - quota) * extra_price;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int petrol_next_month, quota;

    cin >> petrol_next_month >> quota;

    quota += 60;
    cout << petrol_cost(quota, petrol_next_month);
    return 0;
}
