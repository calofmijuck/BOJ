#include <bits/stdc++.h>
using namespace std;

typedef complex<double> Complex;

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
        double ang = 2 * acos(-1) / len * (inv ? -1 : 1);
        Complex wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len) {
            Complex w(1);
            for(int j = 0; j < len / 2; ++j) {
                Complex u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if(inv) {
        for(int i = 0; i < n; i++) 
            a[i] /= n;
    }
}

void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
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
        res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int main() {
    int n, m, mx = 0;
    scanf("%d", &n);
    vector<int> num;
    for(int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        num.push_back(x);
        mx = max(mx, x);
    }
    int rs = 1; 
    while(rs < 2 * mx) 
        rs <<= 1;
    vector<int> a(rs), b(rs), ans;
    a[0] = b[0] = 1;
    for(int i = 0; i < num.size(); ++i)
        a[num[i]] = b[num[i]] = 1;
    multiply(a, b, ans);
    scanf("%d", &m);
    int cnt = 0;
    for(int i = 0; i < m; ++i) {
        int x; scanf("%d", &x);
        if(x <= 2 * mx && ans[x] > 0) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
