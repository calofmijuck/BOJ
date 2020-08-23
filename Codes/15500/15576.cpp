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
    string a, b;
    cin >> a >> b;
    int sz = max(a.size(), b.size());
    vector<int> x(sz), y(sz), res;
    for(int i = 0; i < a.size(); ++i)
        x[i] = a[a.size() - 1 - i] - '0';
    for(int i = 0; i < b.size(); ++i)
        y[i] = b[b.size() - 1 - i] - '0';
    multiply(x, y, res);
    stack<int> nums;
    for(int i = 0; i < res.size(); ++i) {
        int r = res[i] % 10;
        if(i + 1 < res.size()) {
            res[i + 1] += res[i] / 10;
            nums.push(r);
        } else
            nums.push(res[i]);
    }
    bool flag = true;
    while(!nums.empty()) {
        int k = nums.top();
        nums.pop();
        if(flag && k == 0)
            continue;
        else
            flag = false;
        cout << k;
    }
    if(flag)
        cout << 0;
    return 0;
}