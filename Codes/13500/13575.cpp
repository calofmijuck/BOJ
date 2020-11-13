#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

vector<ll> multiply(const vector<ll> &a, const vector<ll> &b) {
    vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < (int) max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, false); fft(fb, false);
    for(int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    vector<ll> res(n);
    for(int i = 0; i < n; i++) {
        res[i] = ll(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
        if(res[i])
            res[i] = 1;
    }
    return res;
}

vector<ll> pow(vector<ll> a, int k) {
    int exp = k;
    vector<ll> ret = {1};
    while(exp > 0) {
        if(exp & 1)
            ret = multiply(ret, a);
        exp >>= 1;
        a = multiply(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> a(1001, 0);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    vector<ll> res = pow(a, k);

    for(int i = 1; i < (int) res.size(); ++i) {
        if(res[i] > 0)
            cout << i << ' ';
    }
    return 0;
}