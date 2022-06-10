#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dx[4] = {1, -1, -1, 1}, dy[4] = {1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    pair<ll, ll> center;
    cin >> center.first >> center.second;

    ll radius;
    cin >> radius;

    for (int i = 0; i < 4; ++i) {
        int x = center.first + dx[i] * radius;
        int y = center.second + dy[i] * radius;

        cout << x << ' ' << y << '\n';
    }

    return 0;
}
