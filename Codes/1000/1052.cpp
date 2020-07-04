#include <bits/stdc++.h>
using namespace std;

int popCnt(int x) {
    int ret = 0;
    while(x > 0) {
        if(x & 1) ret++;
        x >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while(popCnt(n) > k) {
        int a = n & (-n);
        n += a;
        ans += a;
    }
    cout << ans;
    return 0;
}