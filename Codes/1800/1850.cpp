#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    else return gcd(b % a, a);
}

int main() {
    ll a, b, g;
    scanf("%lld %lld", &a, &b);
    g = gcd(a, b);
    while(g--) printf("1");
    return 0;
}
