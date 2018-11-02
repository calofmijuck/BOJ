#define _USE_MATH_DEFINES
#include <cmath>
#include <complex>
#include <iostream>
#include <valarray>

using namespace std;

typedef complex<double> Complex;
typedef valarray<Complex> CArray;

// Cooley - Tukey FFT
void fft(CArray& x) {
    size_t N = x.size();
    if(N <= 1) {
        return;
    }

    // Divide
    CArray even = x[slice(0, N / 2, 2)];
    CArray odd = x[slice(1, N / 2, 2)];

    // Conquer
    fft(even);
    fft(odd);

    // Merge
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
    Complex arr[] = {1.0, 1.0, 1.0, 1.0, 0, 0, 0, 0};
    CArray data(arr, 8);

    fft(data);
    for(int i = 0; i < data.size(); i++) {
        cout << data[i] << ' ';
    }
    puts("");

    ifft(data);
    for(int i = 0; i < data.size(); i++) {
        cout << data[i] << ' ';
    }
    puts("");
    return 0;
}
