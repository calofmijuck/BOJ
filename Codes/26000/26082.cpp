#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int price, effect, my_price;
    cin >> price >> effect >> my_price;
    cout << 3 * my_price * (effect / price);
    return 0;
}
