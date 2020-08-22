#include <bits/stdc++.h>
using namespace std;

#define MAX_N 400001
#define MOD 1000003

typedef long long ll;
typedef complex<long double> Complex;

void fft(vector<Complex> &a, bool inv) {
    int n = a.size();
    for(int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for(; j >= bit; bit >>= 1) 
            j -= bit;
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(int len = 2; len <= n; len <<= 1) {
        vector<Complex> w(len / 2);
        for(int i = 0; i < len / 2; ++i) {
            long double ang = 2 * i * acos(-1.0L) / len * (inv ? -1 : 1);
            w[i] = Complex(cos(ang), sin(ang));
        }
        for(int i = 0; i < n; i += len) {
            for(int j = 0; j < len / 2; ++j) {
                Complex u = a[i + j], v = a[i + j + len / 2] * w[j];
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
            }
        }
    }
    if(inv) {
        for(int i = 0; i < n; i++) 
            a[i] /= n;
    }
}

void multiply(const vector<ll> &a, const vector<ll> &b, vector<ll> &res) {
    vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    fa.resize(n); fb.resize(n); res.resize(n);
    fft(fa, false); fft(fb, false);
    for(int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    for(int i = 0; i < n; i++)
        res[i] = (ll) (fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

ll modfac[MAX_N] = {1, 1};
ll modfacinv[MAX_N] = {1, 1};

ll fastExp(ll n, ll x) {
    ll ret = 1;
    while(x > 0) {
        if(x & 1)
            (ret *= n) %= MOD;
        (n *= n) %= MOD;
        x >>= 1;
    }
    return ret;
}

void precalc() {
    for(int i = 2; i < 400001; ++i) {
        modfac[i] = modfac[i - 1] * i % MOD;
        modfacinv[i] = modfacinv[i - 1] * fastExp(i, MOD - 2) % MOD;
    }
}

ll choose(int n, int k) {
    return modfac[n] * modfacinv[k] % MOD * modfacinv[n - k] % MOD;
}

int main() {
    precalc();
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    vector<ll> l(n + 1), t(n + 1);
    ll sum = 0;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &l[i]);
    for(int j = 1; j <= n; ++j)
        scanf("%d", &t[j]);

    vector<ll> x(n + 1), y(n + 1), res;
    ll apow = fastExp(a, n - 1), bpow = fastExp(b, n - 1);
    ll b_t = 1;
    for(int i = n; i >= 2; --i) {
        ll k = choose(2 * n - i - 2, n - i) * apow % MOD;
        k = k * b_t % MOD * l[i] % MOD;
        x[i] = b_t * modfacinv[n - i] % MOD;
        (b_t *= b) %= MOD;
        (sum += k) %= MOD;
    }
    ll a_t = 1;
    for(int j = n; j >= 2; --j) {
        ll k = choose(2 * n - j - 2, n - j) * bpow % MOD;
        k = k * a_t % MOD * t[j] % MOD;
        y[j] = a_t * modfacinv[n - j] % MOD;
        (a_t *= a) %= MOD;
        (sum += k) %= MOD;
    }
    
    multiply(x, y, res);
    ll sum2 = 0;
    for(int k = 4; k <= 2 * n; ++k) {
        sum2 += modfac[2 * n - k] * (res[k] % MOD) % MOD;
        sum2 %= MOD;
    }
    (sum2 *= c) %= MOD;
    printf("%lld", (sum + sum2) % MOD);
    return 0;
}
