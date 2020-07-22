#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    if((a + b) % 2 != 0) {
        cout << -1;
        return 0;
    }
    int x = (a + b) / 2;
    int y = a - x;
    if(x < 0 || y < 0) {
        cout << -1;
        return 0;
    }
    cout << max(x, y) << ' ' << min(x, y);
    return 0;
}