#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll mod_mult(ll x, ll y, ll mod) {
    return (ll) ((__int128) x * y % mod);
}

ll mod_pow(ll x, ll y, ll mod) {
    ll prod = 1;
    x %= mod;
    while(y > 0) {
        if(y % 2 == 1)
            prod = mod_mult(prod, x, mod);
        x = mod_mult(x, x, mod);
        y >>= 1;
    }
    return prod;
}

ll gcd(ll x, ll y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}

bool miller_rabin(ll n) {
    if(n <= 40) {
        for(ll a : bases) {
            if(n == a) return true;
            if(a > n) break;
        }
        return false;
    }
        
    int r = 0;
    ll d = n - 1;
    while(d % 2 == 0) {
        r++;
        d >>= 1;
    }

    for(ll a : bases) {
        if(n % a == 0) return false;
        ll x = mod_pow(a, d, n);
        if(x == 1 || x == n - 1)
            continue;

        bool cont_flag = false;
        for(int i = 0; i < r - 1; ++i) {
            x = mod_mult(x, x, n);
            if(x == n - 1) {
                cont_flag = true;
                break;
            }
        }
        if(cont_flag) continue;
        else return false;
    }
    return true;
}

ll pollard_rho(ll n) {
    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll c = rand() % (n - 1) + 1;
    ll d = 1;

    while(d == 1) {
        x = (mod_mult(x, x, n) + c) % n;
        y = (mod_mult(y, y, n) + c) % n;
        y = (mod_mult(y, y, n) + c) % n;
        d = gcd(abs(x - y), n);
    }
    if(!miller_rabin(d)) return pollard_rho(d);        
    else return d;
}

void factorize(ll n, vector<ll>& exponents){
    if(n % 2 == 0) {
        int two = 0;
        while(n % 2 == 0) {
            n >>= 1;
            ++two;
        }
        exponents.push_back(two);
    }
    if(n == 1) return;
    while(!miller_rabin(n)) {
        ll divisor = pollard_rho(n);
        if(n % divisor == 0) {
            int exp = 0;
            while(n % divisor == 0) {
                n /= divisor;
                ++exp;
            }
            exponents.push_back(exp);
        }
        if(n == 1) break;
    }
    if(n != 1) exponents.push_back(1);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    vector<ll> exponents;
    cin >> n;
    factorize(n, exponents);
    ll ans = 1;
    for(ll e : exponents) {
       ans *= (e + 1);
    }
    cout << ans;
}