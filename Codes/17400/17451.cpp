#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[303030];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    ll mx = 0, idx = 0;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    ll speed = arr[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        if(arr[i] > speed) speed = arr[i];
        else {
            ll r = (speed + arr[i] - 1) / arr[i];
            if(r != 1)
                speed = r * arr[i];
        }
    }
    cout << speed;
}