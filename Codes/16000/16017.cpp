#include <bits/stdc++.h>
using namespace std;

bool check_telemarketer(vector<int>& digits) {
    if (digits[0] != 8 and digits[0] != 9) {
        return false;
    }

    if (digits[1] != digits[2]) {
        return false;
    }

    if (digits[3] != 8 and digits[3] != 9) {
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> digits(4);
    for (int i = 0; i < 4; ++i) {
        cin >> digits[i];
    }

    if (check_telemarketer(digits)) {
        cout << "ignore";
    } else {
        cout << "answer";
    }
    return 0;
}
