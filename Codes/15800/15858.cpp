#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    ll k = (ll) a * b;
    printf("%lld.", k / c);
    for(int i = 0; i < 15; ++i) {
        k = k % c;
        k *= 10;
        printf("%lld", k / c);
    }
    return 0;
}
