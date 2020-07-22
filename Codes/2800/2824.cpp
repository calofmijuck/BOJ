#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000

typedef long long ll;
typedef pair<int, int> pii;

bool prime[40040];

void sieve() {
    memset(prime, true, sizeof(prime));
    for(int p = 2; p <= 40000; ++p) {
        if(!prime[p]) continue;
        for(int i = p * p; i <= 40000; i += p)
            prime[i] = false;
    }
}

vector<pii> factorize(int x) {
    vector<pii> ret;
    for(int i = 2; i < 40000; ++i) {
        if(!prime[i]) continue;
        int cnt = 0;
        while(x % i == 0) {
            cnt++;
            x /= i;
        }
        if(cnt != 0) ret.emplace_back(i, cnt);
        if(x == 1) break;
    }
    if(x != 1)
        ret.emplace_back(x, 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    sieve();
    map<int, int> a;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vector<pii> factors = factorize(x);
        for(pii factor : factors) {
            int p = factor.first, e = factor.second;
            a[p] = a[p] + e;
        }
    }
    cin >> m;
    map<int, int> b;
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        vector<pii> factors = factorize(x);
        for(pii factor : factors) {
            int p = factor.first, e = factor.second;
            b[p] = b[p] + e;
        }
    }
    map<int, int>::iterator it = a.begin();
    ll ans = 1;
    bool flag = false;
    for(; it != a.end(); ++it) {
        ll p = it -> first;
        if(b[p] != 0) {
            int e = min(it -> second, b[p]);
            for(int i = 0; i < e; ++i) {
                if(ans * p > MOD) flag = true;
                ans = (ans * p) % MOD;
            }
        }
    }
    if(!flag) cout << ans;
    else {
        int exp = 0, k = ans;
        while(k > 0) exp++, k /= 10;
        for(int i = 0; i < 9 - exp; ++i) cout << '0';
        cout << ans;
    }
    return 0;
}