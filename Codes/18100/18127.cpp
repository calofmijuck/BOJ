#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long a, b;
    cin >> a >> b;
    cout << 1 - b * (a - 3) + (a - 2) * ((b + 1) * b / 2 + b);
    return 0;
}
