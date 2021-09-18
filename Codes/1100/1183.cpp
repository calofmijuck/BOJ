#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> diff;
    for (int i = 0; i < n; ++i) {
        int promised, arrival;
        cin >> promised >> arrival;
        diff.push_back(arrival - promised);
    }
    sort(diff.begin(), diff.end());
    if (n % 2 == 1) {
        cout << 1;
    } else {
        cout << diff[n / 2] - diff[n / 2 - 1] + 1;
    }
    return 0;
}
