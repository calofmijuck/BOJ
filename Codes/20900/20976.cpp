#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> numbers(3);
    for (int i = 0; i < 3; ++i) {
        cin >> numbers[i];
    }

    sort(begin(numbers), end(numbers));

    cout << numbers[1];

    return 0;
}
