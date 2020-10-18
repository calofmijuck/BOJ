#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll x1, x2, y1, y2, z1, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
    ll n, x, mx = 0, sum = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        mx = max(x, mx);
        sum += x;
    }
    if(sum >= dist) {
        if(mx <= dist)
            cout << "YES";
        else if(2 * mx - dist > sum)
            cout << "NO";
        else
            cout << "YES";
    } else
        cout << "NO";
    return 0;
}