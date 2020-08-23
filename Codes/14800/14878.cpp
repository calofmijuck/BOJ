#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fft(vector<ll> &a, bool inv) {
    int n = a.size();
    for(int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for(; j >= bit; bit >>= 1) 
            j -= bit;
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(int len = 2; len <= n; len <<= 1) {
        for(int i = 0; i < n; i += len) {
            for(int j = 0; j < len / 2; ++j) {
                ll u = a[i + j], v = a[i + j + len / 2];
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
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
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
        res[i] = fa[i];
}

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int len = 1 << 16;
    vector<ll> x(len), y(len), res;
    int psum = 0;
    x[0] = y[0] = 1;
    for(int i = 0; i < n; ++i) {
        psum ^= a[i];
        x[psum]++, y[psum]++;
    }
    ll sum = 0;
    for(int i = 0; i < len; ++i)
        sum += x[i];
    multiply(x, y, res);
    ll ans = 0, cnt = 0;
    res[0] -= sum;
    for(int i = 0; i < len; ++i) {
        if(res[i] / 2 > cnt) {
            ans = i;
            cnt = res[i] / 2;
        }
    }
    printf("%lld %lld", ans, cnt);
    return 0;
}
