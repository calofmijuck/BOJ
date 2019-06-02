#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    if(n == 0) {
        puts("NO");
        return 0;
    }
    while(n > 0) {
        int r = n % 3;
        if(r == 2) {
            puts("NO");
            return 0;
        }
        n /= 3;
    }
    puts("YES");
    return 0;
}
