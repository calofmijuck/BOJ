#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    int target_r[2] = { k % 10, 2 * k % 10 };

    int count = 0;
    vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        int r = i % 10;
        if (r == target_r[0] or r == target_r[1]) {
            continue;
        }

        count++;
        numbers.push_back(i);
    }

    cout << count << '\n';
    for (int e : numbers) {
        cout << e << ' ';
    }
    return 0;
}
