#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> Complex;

#define MAX_N 50005

int max_len = 0, sz[MAX_N];
ll n, cnt[MAX_N];
bool visited[MAX_N];
vector<int> adj[MAX_N];
vector<ll> curr, acc;

bitset<MAX_N> prime;

// Sieve
void sieve(int n = 50000) {
    prime.flip();
    prime[0] = prime[1] = false;
    for (ll p = 2; p * p <= n; ++p) {
        if (!prime[p]) {
            continue;
        }

        for (int i = p * p; i <= n; i += p) {
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

void multiply(const vector<ll>& a, const vector<ll>& b, vector<ll>& res) {
    vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
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

// Centroid
int get_size(int v, int parent) {
    sz[v] = 1;
    for (int next : adj[v]) {
        if (next == parent || visited[next])
            continue;
        sz[v] += get_size(next, v);
    }
    return sz[v];
}

int find_centroid(int v, int parent, int lim) {
    for (int next : adj[v]) {
        if (next == parent || visited[next])
            continue;
        if (sz[next] > lim)
            return find_centroid(next, v, lim);
    }
    return v;
}

void update(int v, int parent, int depth) {
    max_len = max(depth, max_len);
    ++curr[depth];
    for (int next : adj[v]) {
        if (next == parent || visited[next])
            continue;
        update(next, v, depth + 1);
    }
}

bool compare(int a, int b) {
    return sz[a] < sz[b];
}

void solve(int v) {
    int lim = get_size(v, -1) / 2;
    int centroid = find_centroid(v, -1, lim);
    visited[centroid] = true;

    acc.clear();
    acc.resize(sz[centroid] + 1);
    acc[0] = 1;

    for (int next : adj[centroid]) {
        if (visited[next]) {
            continue;
        }

        max_len = 0;
        curr.clear();
        curr.resize(sz[next] + 1, 0);
        update(next, centroid, 1);

        vector<ll> res;
        multiply(acc, curr, res);
        int bound = min(MAX_N, (int) res.size());
        for (int i = 1; i < bound; ++i)
            cnt[i] += res[i];
        if ((int) acc.size() <= max_len)
            acc.resize(max_len + 1);
        for (int i = 0; i <= max_len; ++i)
            acc[i] += curr[i];
    }

    for (int next : adj[centroid]) {
        if (!visited[next])
            solve(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(1);
    sieve();
    ll ans = 0;
    for (int i = 2; i < n; ++i) {
        if (prime[i])
            ans += cnt[i];
    }
    cout << fixed;
    cout.precision(10);
    ll total = (ll) n * (n - 1) / 2;
    cout << 1.0 * ans / total;
    return 0;
}
