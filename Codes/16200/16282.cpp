#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, t = 2;
    scanf("%lld", &n);
    for(int i = 2; i < 65; ++i) {
        t <<= 1;
        if(t * i - 1 >= n) {
            printf("%d", i - 1);
            break;
        }
    }
    return 0;
}
