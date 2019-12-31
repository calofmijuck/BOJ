#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    int cnt = 1;
    while(y != 0) {
        if(y % 10 == 1) y /= 10;
        else if(y % 2 == 0) y >>= 1;
        else break;
        cnt++;
        if(x == y) {
            cout << cnt;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
