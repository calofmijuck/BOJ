#include <bits/stdc++.h>
using namespace std;

int max_area(int n) {
    vector<int> x_coord(n);
    vector<int> y_coord(n);
    for (int i = 0; i < n; ++i) {
        cin >> x_coord[i] >> y_coord[i];
    }

    sort(begin(x_coord), end(x_coord));
    sort(begin(y_coord), end(y_coord));

    return (*x_coord.rbegin() - *x_coord.begin()) * (*y_coord.rbegin() - *y_coord.begin());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    cout << max_area(n);
    return 0;
}
