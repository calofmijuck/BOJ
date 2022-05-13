#include <bits/stdc++.h>
using namespace std;

template<typename T>
class extended_euclidean {
public:
    // ax + by = gcd(a, b)
    T a, x, b, y, gcd;

    extended_euclidean(T a, T b) {
        T old_r = a, r = b;
        T old_s = 1, s = 0;
        T old_t = 0, t = 1;

        while (r != 0) {
            T quotient = old_r / r;
            T tmp;

            tmp = r;
            r = old_r - quotient * r;
            old_r = tmp;

            tmp = s;
            s = old_s - quotient * s;
            old_s = tmp;

            tmp = t;
            t = old_t - quotient * t;
            old_t = tmp;
        }

        std::tie(a, x, b, y, gcd) = {a, old_s, b, old_t, old_r};
    }
};

int modular_inverse(int x, int m) {
    int inverse = extended_euclidean<int>(x, m).x;
    return (inverse < 0) ? inverse + m : inverse;
}

int chinese_remainder_theorem(vector<int>& remainder, vector<int>& modulus) {
    int product = 1;
    for (int m : modulus) {
        product *= m;
    }

    int result = 0;
    for (int i = 0; i < (int) modulus.size(); ++i) {
        int p = product / modulus[i];
        result += remainder[i] * modular_inverse(p, modulus[i]) * p;
        result %= product;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> input;
    input.resize(3);
    for (int i = 0; i < 3; ++i) {
        cin >> input[i];
        input[i]--;
    }

    vector<int> periods = {15, 28, 19};
    cout << chinese_remainder_theorem(input, periods) + 1;
}
