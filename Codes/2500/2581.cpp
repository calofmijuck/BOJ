#include <bits/stdc++.h>
using namespace std;

bitset<10101> prime;

int main() {
    int m, n, pmin = 10101, psum = 0;
    prime.set();
    prime[1] = 0;
    scanf("%d %d", &m, &n);
    for(int p = 2; p <= 10101; ++p) {
        if(prime[p]) {
            for(int k = p * p; k <= 10101; k += p)
                prime[k] = 0;
        }
    }
    for(int i = m; i <= n; i++) {
        if(prime[i]) {
            psum += i;
            if(i < pmin) pmin = i;
        }
    }
    if(psum == 0) puts("-1");
    else printf("%d\n%d", psum, pmin);
    return 0;
}
