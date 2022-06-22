#include <bits/stdc++.h>
using namespace std;

int base[5] = { 1, 2, 6, 24, 120 };

int base_10(int number) {
    int result = 0;
    for (int i = 0; number > 0; ++i) {
        result += (number % 10) * base[i];
        number /= 10;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (true) {
        int number;
        cin >> number;
        if (number == 0) {
            break;
        }

        cout << base_10(number) << '\n';
    }
    return 0;
}
