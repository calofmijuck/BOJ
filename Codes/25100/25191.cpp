#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int chicken, coke, beer;
    cin >> chicken >> coke >> beer;

    cout << min(chicken, (coke / 2) + beer);
    return 0;
}
