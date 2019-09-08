#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[202], arr[202];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    cout << n - ans;
    return 0;
}