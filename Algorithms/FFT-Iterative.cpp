#include <bits/stdc++.h>
using namespace std;

using dtype = int;
using base = complex<double>;

void fft(vector<base>& a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * acos(-1) / len * (inv ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; ++j) {
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++)
            a[i] /= n;
    }
}

void multiply(const vector<dtype>& a, const vector<dtype>& b, vector<dtype>& res) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    fa.resize(n); fb.resize(n); res.resize(n);
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    for (int i = 0; i < n; i++)
        res[i] = dtype(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}
