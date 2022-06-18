#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int belts;
    cin >> belts;

    ll rotation = 1;
    bool clockwise = false;
    for (int i = 0; i < belts; ++i) {
        ll a, b;
        bool skewed;
        cin >> a >> b >> skewed;

        rotation = rotation * b / a;
        if (skewed) {
            clockwise = !clockwise;
        }
    }

    cout << (int) clockwise << ' ' << rotation;
    return 0;
}
