#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    if(n & (n - 1)) puts("0");
    else puts("1");
    return 0;
}
