#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef complex<double> Complex;
typedef valarray<Complex> CArray;

// Cooley - Tukey FFT
void fft(CArray& x) {
    size_t N = x.size();
    if(N <= 1) {
        return;
    }
    CArray even = x[slice(0, N / 2, 2)];
    CArray odd = x[slice(1, N / 2, 2)];
    fft(even);
    fft(odd);
    for(size_t k = 0; k < N / 2; ++k) {
        Complex t = polar(1.0, -2 * M_PI * k / N) * odd[k];
        x[k] = even[k] + t;
        x[k + N / 2] = even[k] - t;
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
    for(int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    ifft(fa);
    res.resize(n);
    for(int i = 0; i < n; i++) {
        res[i] = (int) (fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
    }
}

int main() {
    int n, input;
    CArray a, b;
    valarray<int> ans;
    scanf("%d", &n);
    int x = 1;
    while(x < 2 * n) {
        x <<= 1;
    }
    a.resize(x); b.resize(x);
    for(int i = 0; i < n; i++) {
        scanf("%d", &input);
        Complex c(input, 0);
        a[i] = c;
        a[i + n] = c;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &input);
        Complex c(input, 0);
        b[n - i - 1] = c;
    }
    multiply(a, b, ans);
    int ret = 0;
    for(int i = n; i < 2 * n; i++) {
        ret = max(ret, ans[i]);
    }
    printf("%d", ret);
    return 0;
}
