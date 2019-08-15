#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int arr[10101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) ans += abs(arr[i] - arr[j]);
    }
    cout << ans;
}
