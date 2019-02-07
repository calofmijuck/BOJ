#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    ll prod = 1, tmp;
    for(ll i = 2; i <= n; ++i) {
        tmp = i;
        while(tmp % 10 == 0) tmp /= 10;
        prod *= tmp;
        while(prod % 10 == 0) prod /= 10;
        prod %= 1000000000;
    }
    printf("%d", prod % 10);
    return 0;
}
