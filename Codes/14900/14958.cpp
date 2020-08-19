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

int m, n;
string a, b;
vector<int> ans;

vector<int> process(string str, char c, bool rev) {
    vector<int> ret;
    int i = (rev ? str.size() - 1 : 0);
    while(0 <= i && i <= str.size()) {
        if(str[i] == c) ret.push_back(1);
        else ret.push_back(0);
        i = i + (rev ? -1 : 1);
    }
    return ret;
}

void solve(char c, char d) {
    vector<int> my, op, t;
    op = process(a, c, false);
    my = process(b, d, true);
    multiply(op, my, t);
    for(int i = m - 1; i < n + m - 1; ++i)
        ans[i] += t[i];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> a >> b;
    ans.resize(n + m);
    solve('S', 'R');
    solve('P', 'S');
    solve('R', 'P');
    int mx = 0;
    for(int i = m - 1; i < n + m - 1; ++i)
        mx = max(mx, ans[i]);
    cout << mx;
    return 0;
}
