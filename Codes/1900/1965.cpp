#include <bits/stdc++.h>
using namespace std;

int box[1010], dp[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> box[i];
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(box[i] > box[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}