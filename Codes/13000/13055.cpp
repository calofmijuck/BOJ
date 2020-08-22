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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    int len = str.size();
    vector<int> a(len), b(len), res;
    for(int i = 0; i < len; ++i) {
        if(str[i] == 'A')
            a[i] = 1;
        else
            b[len - i - 1] = 1;
    }
    multiply(a, b, res);
    for(int i = len; i < 2 * len - 1; ++i)
        cout << res[i] << '\n';
    return 0;
}