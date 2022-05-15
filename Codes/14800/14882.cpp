#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 786433;

const int primitive_root = 10;
const int third_root = 392448;
const int power = 1 << 18;

void preprocess(unordered_map<int, int>& table) {
    int root_power = 1;
    for (int i = 0; i < mod - 1; ++i) {
        table[root_power] = i;
        root_power = (ll) root_power * primitive_root % mod;
    }
}

void number_theoretic_transform(vector<int>& a) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;

        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = primitive_root * primitive_root * primitive_root;
        for (int i = len; i < power; i <<= 1) {
            wlen = (ll) wlen * wlen % mod;
        }

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = (ll) a[i + j + len / 2] * w % mod;

                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = (ll) w * wlen % mod;
            }
        }
    }
}

// 3-radix NTT
void number_theoretic_transform_radix_3(vector<int>& a) {
    int n = a.size();

    int subarray_size = n / 3;
    vector<int> first(subarray_size), second(subarray_size), third(subarray_size);
    for (int i = 0; i < subarray_size; ++i) {
        first[i] = a[3 * i];
        second[i] = a[3 * i + 1];
        third[i] = a[3 * i + 2];
    }

    number_theoretic_transform(first);
    number_theoretic_transform(second);
    number_theoretic_transform(third);

    int root_power = 1;
    int third_root_squared = (int) (1LL * third_root * third_root % mod);
    for (int i = 0; i < subarray_size; ++i) {
        ll u = (ll) root_power * second[i] % mod;
        ll v = (ll) root_power * root_power % mod * third[i] % mod;

        a[i] = (first[i] + u + v) % mod;
        a[i + subarray_size] = (first[i] + third_root * u + third_root_squared * v) % mod;
        a[i + 2 * subarray_size] = (first[i] + third_root_squared * u + third_root * v) % mod;

        root_power = (ll) root_power * primitive_root % mod;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    unordered_map<int, int> table;
    preprocess(table);

    vector<int> coefficients(mod - 1);

    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> coefficients[i];
    }

    int constant = coefficients[0];
    number_theoretic_transform_radix_3(coefficients);

    int k, q;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> q;
        if (q == 0) {
            cout << constant << '\n';
            continue;
        }

        cout << coefficients[table[q]] << '\n';
    }
    return 0;
}
