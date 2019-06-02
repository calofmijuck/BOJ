#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[10000001], n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll sum = 0, m = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x; cin >> x;
            sum += x;
            dp[x] += 1;
            m = max(m, (ll) x);
        }
    }
    if(sum == 0) {
        puts("0");
        return 0;
    }

    ll half = (sum + 1) >> 1;
    ll on = 0, prev = n * n;
    for(int i = 1; i <= m + 1; ++i) {
        on += (prev -= dp[i - 1]);
        if(on >= half) {
            cout << i;
            break;
        }
    }
    return 0;
}
