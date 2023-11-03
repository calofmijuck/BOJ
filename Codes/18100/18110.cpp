#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> evaluations(n);
    for (int i = 0; i < n; ++i) {
        cin >> evaluations[i];
    }

    sort(begin(evaluations), end(evaluations));

    int remove = round(n * 0.15);
    int sum = 0;
    for (int i = remove; i < n - remove; ++i) {
        sum += evaluations[i];
    }

    cout << round((double) sum / (n - 2 * remove));
    return 0;
}
