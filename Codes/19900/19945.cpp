#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, ans = 32;
    cin >> n;
    unsigned flag = 1 << 31;
    while(flag > 0) {
        if((n & flag) == 0)
            ans--;
        else
            break;
        flag >>= 1;
    }
    cout << max(ans, 1);
    return 0;
}