#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int percentage;
    cin >> percentage;

    cout.precision(10);
    cout << fixed << (double) 100 / percentage << '\n' << (double) 100 / (100 - percentage);
    return 0;
}
