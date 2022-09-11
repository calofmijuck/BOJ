#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int card;
    cin >> card;

    int sum = 0, max = 0;
    for (int i = 0; i < card; ++i) {
        int number;
        cin >> number;

        if (number > max) {
            max = number;
        }

        sum += number;
    }

    cout << sum - max;
    return 0;
}
