#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    cout << ((double) a * (100 - b) / 100 < 100);
    return 0;
}
