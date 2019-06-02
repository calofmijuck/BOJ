#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[1010][1010], n;

ll check(ll x) {
    ll ret = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ret += min(x, (ll) arr[i][j]);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll sum = 0, m = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            m = max(m, (ll) arr[i][j]);
            sum += arr[i][j];
        }
    }
    ll left = 0, right = m, mid;
    while(left < right) {
        mid = (left + right) >> 1;
        ll on = check(mid);
        if(on * 2 >= sum) right = mid;
        else left = mid + 1;
    }
    cout << right;
    return 0;
}
