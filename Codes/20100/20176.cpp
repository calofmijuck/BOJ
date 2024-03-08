#include <bits/stdc++.h>
using namespace std;

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

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res) {
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
        res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

void receive_data(vector<int>& data, int offset) {
    int count, x;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        cin >> x;
        data[x + offset] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    const int lim = 30000;
    vector<int> upper(2 * lim + 1), middle(2 * lim + 1), lower(2 * lim + 1);
    vector<int> ans;

    receive_data(upper, lim);
    receive_data(middle, lim);
    receive_data(lower, lim);

    multiply(upper, lower, ans);

    int paths = 0;
    for (int i = 0; i < (int) ans.size(); i += 2) {
        if (ans[i] == 0) {
            continue;
        }

        if (middle[i / 2] != 0) {
            paths += ans[i];
        }
    }

    cout << paths;
}
