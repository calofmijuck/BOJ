#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using base = complex<double>;

const int width = 2;
const int mod = pow(10, width);

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

void multiply(const vector<ll>& a, const vector<ll>& b, vector<ll>& res) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) max(a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    fa.resize(n); fb.resize(n); res.resize(n);
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    for (int i = 0; i < n; i++)
        res[i] = ll(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

vector<ll> parse_int(string& s) {
    vector<ll> res;
    int digits = 0, len = s.size();
    for (int i = len - 1; i >= 0; i -= width) {
        int base = 1;
        for (int j = 0; j < width; ++j) {
            if (i - j < 0) {
                break;
            }

            digits += (s[i - j] - '0') * base;
            base *= 10;
        }

        res.push_back(digits);
        digits = 0;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;

    vector<ll> a_coeff = parse_int(a);
    vector<ll> b_coeff = parse_int(b);

    vector<ll> prod;
    multiply(a_coeff, b_coeff, prod);

    for (int i = 0; i < (int) prod.size() - 1; ++i) {
        prod[i + 1] += prod[i] / mod;
        prod[i] %= mod;
    }

    bool first = true;
    for (int i = prod.size() - 1; i >= 0; --i) {
        if (first && prod[i] == 0) {
            continue;
        }

        if (first) {
            cout << prod[i];
            first = false;
        } else {
            cout << setfill('0') << setw(width) << prod[i];
        }
    }

    // 0 * 0
    if (first) {
        cout << 0;
    }
    return 0;
}
