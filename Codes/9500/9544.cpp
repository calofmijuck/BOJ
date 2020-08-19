#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int k, m; scanf("%d %d", &k, &m);
        
        // calculate fib mod m;
        vector<int> fib(k + 1);
        fib[0] = fib[1] = 1;
        for(int i = 2; i <= k; ++i)
            fib[i] = (fib[i - 1] + fib[i - 2]) % m;
        
        // calculate expansion
        vector<int> coef(k + 1);
        coef[0] = -fib[1], coef[1] = 1;
        for(int i = 2; i <= k; ++i) {
            ll p1 = coef[0], p2 = coef[1], xk = fib[i];
            coef[0] = (int) (-xk * p1 % m); 
            for(int j = 1; j < i; ++j) {
                coef[j] = (int) ((p1 - xk * p2) % m);
                p1 = p2, p2 = coef[j + 1];
            }
            coef[i] = 1;
        }

        // find next element
        ll ans = 0;
        for(int i = 0; i < k; ++i) {
            ll x; scanf("%lld", &x);
            ans -= (x * coef[i]) % m;
            (ans += m) %= m;
        }
        printf("%lld\n", ans);
    }
    return 0;
}