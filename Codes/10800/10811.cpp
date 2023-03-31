#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int items, operations;
    cin >> items >> operations;

    vector<int> bucket(items + 1);
    for (int i = 0; i <= items; ++i) {
        bucket[i] = i;
    }

    for (int i = 0; i < operations; ++i) {
        int left, right;
        cin >> left >> right;

        reverse(begin(bucket) + left, begin(bucket) + right + 1);
    }

    for (int i = 1; i <= items; ++i) {
        cout << bucket[i] << ' ';
    }
    return 0;
}
