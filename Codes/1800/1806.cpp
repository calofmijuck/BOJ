#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num[100010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, s, sum = 0, l = 0, r = 0;
    cin >> n >> s;
    ll len = 1e9;
    for(int i = 0; i < n; ++i)
        cin >> num[i];
    while(true) {
        if(sum < s) {
            if(r == n) break;
            sum += num[r++];
        } else {
            sum -= num[l++];
            len = min(len, r - l + 1);
        }            
    }
    cout << ((len == 1e9) ? 0 : len);
    return 0;
}
