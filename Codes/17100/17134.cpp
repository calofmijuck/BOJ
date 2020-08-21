#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000001

bool prime[MAX_N];

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
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int p = 2; p * p <= MAX_N; ++p) {
		if(!prime[p]) continue;
		for(int i = p * p; i <= MAX_N; i += p)
			prime[i] = false;
	}
	vector<int> a(MAX_N), b(MAX_N), res;
	for(int i = 2; i <= MAX_N; ++i) {
		if(prime[i]) {
			a[i] = 1;
			if(i * 2 <= MAX_N)
				b[2 * i] = 1;
		}
	}
	multiply(a, b, res);
	int t; scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		int n; scanf("%d", &n);
		printf("%d\n", res[n]);
	}
	return 0;
}
