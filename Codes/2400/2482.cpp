#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000003

typedef long long ll;

ll dp[1010][1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, k;
    cin >> n >> k;
    if(k == 1) {
        cout << n;
        return 0;
    } else if(k > n / 2) {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; ++i) dp[i][1] = i;
    for(int i = 2; i <= n; i += 2) dp[i][i / 2] = 2;
    for(int i = 4; i <= n; ++i) {
        for(int k = 2; k <= n / 2; ++k) {
            dp[i + 1][k] = (dp[i][k] + dp[i - 1][k - 1]) % MOD;
        }   
    }
    cout << dp[n][k];
    return 0;
}
