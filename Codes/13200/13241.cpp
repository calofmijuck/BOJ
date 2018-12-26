#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    else return gcd(b % a, a);
}

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", a * b / gcd(a, b));
    return 0;
}
