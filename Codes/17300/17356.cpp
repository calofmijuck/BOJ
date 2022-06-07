#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int wook, je;
    cin >> wook >> je;

    long double m = (long double) (je - wook) / 400;

    cout.precision(10);
    cout << fixed << 1 / (1 + pow(10, m));
    return 0;
}
