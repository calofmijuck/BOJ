#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> Complex;

#define MAX_N 50005

ll prime_path_count = 0;

int subtree_size[MAX_N];
int accumulator[MAX_N], node_depth[MAX_N];

vector<int> tree[MAX_N];

bitset<MAX_N> prime, visited;
vector<int> primes;

// Sieve
void sieve(ll n = MAX_N - 1) {
    prime.flip();
    prime[0] = prime[1] = false;
    for (ll p = 2; p <= n; ++p) {
        if (!prime[p]) {
            continue;
        }

        primes.push_back(p);
        for (ll i = p * p; i <= n; i += p) {
            prime[i] = false;
        }
    }
}

// Fast Fourier Transform
void fft(vector<Complex>& a, bool inv) {
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
        Complex wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            Complex w(1);
            for (int j = 0; j < len / 2; ++j) {
                Complex u = a[i + j], v = a[i + j + len / 2] * w;
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

void multiply(int* a, int size_a, int* b, int size_b, vector<int>& res) {
    vector<Complex> fa(a, a + size_a), fb(b, b + size_b);
    int n = 1;
    while (n < (int) max(size_a, size_b))
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

// Centroid
int get_subtree_size(int v, int parent = -1) {
    subtree_size[v] = 1;
    for (int next : tree[v]) {
        if (next == parent || visited[next]) {
            continue;
        }

        subtree_size[v] += get_subtree_size(next, v);
    }
    return subtree_size[v];
}

int find_centroid(int v, int parent, int lim) {
    for (int next : tree[v]) {
        if (next == parent || visited[next]) {
            continue;
        }

        if (subtree_size[next] > lim) {
            return find_centroid(next, v, lim);
        }
    }
    return v;
}

int dfs(int v, int depth, int parent = -1) {
    node_depth[depth]++;
    int max_depth = depth;
    for (int next : tree[v]) {
        if (next == parent || visited[next]) {
            continue;
        }

        max_depth = max(max_depth, dfs(next, depth + 1, v));
    }
    return max_depth;
}

void solve(int v) {
    int lim = get_subtree_size(v) / 2;
    int centroid = find_centroid(v, -1, lim);
    visited[centroid] = true;
    accumulator[0] = 1;

    int max_previous_depth = 0;

    for (int next : tree[centroid]) {
        if (visited[next]) {
            continue;
        }

        int max_depth = dfs(next, 1);
        max_previous_depth = max(max_depth, max_previous_depth);

        vector<int> result;
        multiply(accumulator, max_previous_depth + 1, node_depth, max_depth + 1, result);
        for (int p : primes) {
            if (p > max_depth + max_previous_depth || p >= (int) result.size()) {
                break;
            }

            prime_path_count += result[p];
        }

        for (int i = 1; i <= max_depth; ++i) {
            accumulator[i] += node_depth[i];
            node_depth[i] = 0;
        }
    }

    memset(accumulator, 0, sizeof(int) * (max_previous_depth + 1));

    for (int next : tree[centroid]) {
        if (!visited[next]) {
            solve(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sieve();

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    solve(1);

    cout << fixed;
    cout.precision(10);

    ll total = (ll) n * (n - 1) / 2;
    cout << 1.0 * prime_path_count / total;
    return 0;
}
