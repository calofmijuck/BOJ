#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int data, check_bit;
        cin >> data >> check_bit;

        int result = check_bit;
        while (data > 0) {
            result ^= data % 2;
            data >>= 1;
        }

        if (result == 0) {
            cout << "Valid\n";
        } else {
            cout << "Corrupt\n";
        }
    }

    return 0;
}
