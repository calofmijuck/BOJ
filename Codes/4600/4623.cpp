#include <bits/stdc++.h>
using namespace std;

bool empty(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            return false;
        }
    }
    return true;
}

void input_and_sort(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int original[2], resized[2];
    while (true) {
        input_and_sort(original, 2);
        input_and_sort(resized, 2);

        if (empty(original, 2) && empty(resized, 2)) {
            break;
        }

        int ratio = min({ resized[0] * 100 / original[0], resized[1] * 100 / original[1], 100 });
        cout << ratio << '%' << '\n';
    }
    return 0;
}
