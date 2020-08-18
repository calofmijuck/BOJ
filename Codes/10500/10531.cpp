#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef complex<double> Complex;
typedef valarray<Complex> CArray;

void fft(CArray& x) {
    size_t n = x.size();
    if(n <= 1) return;
    CArray even = x[slice(0, n / 2, 2)], odd = x[slice(1, n / 2, 2)];
    fft(even); fft(odd);
    for(size_t k = 0; k < n / 2; ++k) {
        Complex t = polar(1.0, -2 * M_PI * k / n) * odd[k];
        x[k] = even[k] + t;
        x[k + n / 2] = even[k] - t;
    }
}

void ifft(CArray& x) {
    x = x.apply(conj);
    fft(x);
    x = x.apply(conj);
    x /= x.size();
}

void multiply(CArray& a, CArray& b, valarray<int>& res) {
    CArray fa(a), fb(b);
    int n = fa.size();
    fft(fa); fft(fb);
    for(int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    ifft(fa);
    res.resize(n);
    for(int i = 0; i < n; ++i)
        res[i] = (int) (fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
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
    CArray a(rs), b(rs);
    Complex c(1, 0);
    a[0] = b[0] = c;
    for(int i = 0; i < num.size(); ++i)
        a[num[i]] = b[num[i]] = c;
    valarray<int> ans;
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