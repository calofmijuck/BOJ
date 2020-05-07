#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define MOD 1000000007

ll B[60], invfac[60] = {1, 1};

// inverse of x in Zp
ll modinv(ll x, ll mod) {
    ll exp = mod - 2;
    ll ret = 1;
    ll base = x;
    while(exp > 0) {
        ll r = exp & 1;
        if(r == 1)
            ret = (ret * base) % mod;
        base  = (base * base) % mod;
        exp >>= 1;
    }
    return ret;
}

// n-th Bernoulli number mod p
ll bernoulli(int n) {
    vl ret;
    for(int i = 0; i <= n; ++i) {
        int k = modinv(i + 1, MOD);
        ret.push_back(k);
        for(int j = i; j > 0; --j) {
            ll v = ret[j - 1] - ret[j];
            v = v + (MOD * (v < 0));
            ret[j - 1] = (j * v) % MOD;
        }
    }
    return ret[0];
}

void modinvfac(ll mod) {
    for(int i = 2; i < 60; ++i)
        invfac[i] = invfac[i - 1] * modinv(i, mod) % mod;
}

void calBernoulli() {
    for(int i = 0; i < 60; ++i)
        B[i] = bernoulli(i);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, k, ans = 0, prod = 1;
    cin >> n >> k;
    modinvfac(MOD); calBernoulli();
    for(int i = k; i >= 0; --i) {
        prod = (prod * n) % MOD;
        ll t = (invfac[k - i + 1] * invfac[i]) % MOD;
        t = t * B[i] % MOD;
        t = t * prod % MOD;
        ans = (ans + t) % MOD;
    }
    ll kfac = 1;
    for(int i = 2; i <= k; ++i)
        kfac = (kfac * i) % MOD;
    cout << (ans * kfac) % MOD;
    return 0;
}
