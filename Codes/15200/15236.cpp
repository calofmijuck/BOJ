#include <bits/stdc++.h>
using namespace std;

int count_spots(int n) {
    // int sum = 0;
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = i; j <= n; ++j) {
    //         sum += i + j;
    //     }
    // }
    // return sum;
    return n * (n + 1) / 2 * (n + 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    cout << count_spots(n);
    return 0;
}
