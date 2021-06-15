#include <bits/stdc++.h>
using namespace std;

int main() {
    int beer, malt, wine, soft_drink, seltzer, water;
    cin >> beer >> malt >> wine >> soft_drink >> seltzer >> water;
    cout << 5 * (beer + malt + wine + soft_drink + seltzer + water);
    return 0;
}
