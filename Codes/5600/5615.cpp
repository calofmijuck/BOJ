#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19};

ll mod_mult(ll x, ll y, ll mod) {
    return (ll) ((__int128) x * y % mod);
}

ll mod_pow(ll x, ll y, ll mod) {
    ll prod = 1;
    x %= mod;
    while(y > 0) {
        if(y % 2 == 1)
            prod = mod_mult(prod, x, mod);
        x = mod_mult(x, x, mod);
        y >>= 1;
    }
    return prod;
}

bool miller_rabin(ll n) {
    if(n <= 22) {
        for(ll a : bases) {
            if(n == a) return true;
            if(a > n) break;
        }
        return false;
    }
        
    int r = 0;
    ll d = n - 1;
    while(d % 2 == 0) {
        r++;
        d >>= 1;
    }

    for(ll a : bases) {
        if(n % a == 0) return false;
        ll x = mod_pow(a, d, n);
        if(x == 1 || x == n - 1)
            continue;

        bool cont_flag = false;
        for(int i = 0; i < r - 1; ++i) {
            x = mod_mult(x, x, n);
            if(x == n - 1) {
                cont_flag = true;
                break;
            }
        }
        if(cont_flag) continue;
        else return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ans += miller_rabin(2 * x + 1);
    }
    cout << ans;
    return 0;
}