#include <bits/stdc++.h>
using namespace std;

bool is_lucky(int ate_number, int first, int second) {
    return ate_number - first - second == 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int ate_number;
    cin >> ate_number;

    int lucky = 0;
    for (int first = 0; first < 100; ++first) {
        for (int second = 0; second < 100; ++second) {
            lucky += is_lucky(ate_number, first, second);
        }
    }
    cout << lucky;
    return 0;
}
