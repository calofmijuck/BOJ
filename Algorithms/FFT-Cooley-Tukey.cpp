#define _USE_MATH_DEFINES
#include <cmath>
#include <complex>
#include <iostream>
#include <valarray>
using namespace std;

using base = complex<double>;
using base_array = valarray<base>;

// Cooley-Tukey FFT
void fft(base_array& x) {
    size_t N = x.size();
    if (N <= 1) {
        return;
    }

    // Divide
    base_array even = x[slice(0, N / 2, 2)];
    base_array odd = x[slice(1, N / 2, 2)];

    // Conquer
    fft(even);
    fft(odd);

    // Merge
    for (size_t k = 0; k < N / 2; ++k) {
        base t = polar(1.0, -2 * M_PI * k / N) * odd[k];
        x[k] = even[k] + t;
        x[k + N / 2] = even[k] - t;
    }
}

void ifft(base_array& x) {
    x = x.apply(conj);
    fft(x);
    x = x.apply(conj);
    x /= x.size();
}

void multiply(base_array& a, base_array& b, valarray<int>& res) {
    base_array fa(a), fb(b);
    int n = fa.size();
    fft(fa); fft(fb);
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    ifft(fa);
    res.resize(n);
    for (int i = 0; i < n; i++) {
        res[i] = (int) (fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
    }
}

int main() {
    base arr[] = { 1.0, 1.0, 1.0, 1.0, 0, 0, 0, 0 };
    base_array data(arr, 8);

    fft(data);
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << ' ';
    }
    puts("");

    ifft(data);
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << ' ';
    }
    puts("");
    return 0;
}
