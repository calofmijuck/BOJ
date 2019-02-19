#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    while(n != 1) {
        printf("%lld ", n);
        if(n % 2) n = 3 * n + 1;
        else n >>= 1;
    }
    printf("%lld", n);
    return 0;
}
