#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int daughters, medals;
    cin >> daughters >> medals;

    int taken = medals / (daughters - 1);
    int min = 0, max = 0;
    if (medals % (daughters - 1) == 0) {
        min = taken * daughters - 1;
        max = min + 1;
    } else {
        min = max = medals + taken;
    }
    cout << min << ' ' << max;
    return 0;
}
