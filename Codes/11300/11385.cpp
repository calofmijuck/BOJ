#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
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

void multiply(const vector<ull> &a, const vector<ull> &b, vector<ull> &res) {
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
        res[i] = (ull) (fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<ull> a, b, res;
    for(int i = 0; i <= n; ++i) {
        ull x; scanf("%llu", &x);
        a.push_back(x);
    }
    for(int i = 0; i <= m; ++i) {
        ull x; scanf("%llu", &x);
        b.push_back(x);
    }
    multiply(a, b, res);
    ull ans = 0;
    for(ull v : res)
        ans ^= v;
    cout << ans;
    return 0;
}