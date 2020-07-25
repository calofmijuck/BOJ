#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int d, h, m;
    cin >> d >> h >> m;
    int ans = 0;
    ans += (d - 11) * 24 * 60;
    ans += (h - 11) * 60;
    ans += (m - 11);
    if(ans < 0) cout << -1;
    else cout << ans;
    return 0;
}