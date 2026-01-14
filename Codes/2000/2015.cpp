#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(vector<int>& arr, int n, int k) {
    vector<ll> prefix_sum(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += arr[i - 1];
        prefix_sum[i] = sum;
    }

    unordered_map<ll, ll> hash;

    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        int target = prefix_sum[i] - k;
        if (hash.find(target) != end(hash)) {
            ans += hash[target];
        }

        hash[prefix_sum[i]]++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << solve(arr, n, k);
    return 0;
}
